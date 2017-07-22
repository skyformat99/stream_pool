#include <stream_worker/stream_worker.hpp>



StreamWorker::StreamWorker()
    : finished(false),
      need_partner(false)
{}


StreamWorker::~StreamWorker()
{}

void
StreamWorker::stop()
{
    {
        std::lock_guard<std::mutex> lock(waiting);
        finished = true;
        this->clear();
    }

    ready.notify_all();
    partner_ready.notify_one();
}


void
StreamWorker::enqueue(StreamSession *const session)
{
    {
        std::lock_guard<std::mutex> lock(waiting);

        if (finished)
            return;

        this->emplace_back(session);
    }

    ready.notify_one();
}


void (StreamSession::*)()
StreamWorker::dequeue(StreamSession *&session)
{
    std::unique_lock<std::mutex> lock(waiting);
    ready.wait(lock, [this] {
        return this->finished || !this->empty();
    });

    if (finished)
        return nullptr;

    session = this->front();

    if (need_partner) {
        need_partner = false;
        partner_ready.notify_one();
        this->pop_front();
        return &Session::writer_loop;
    }

    need_partner = true;
    partner_ready.wait(lock, [this] {
       return this->finished || !this->need_partner;
    });

    if (finished) {
        session->stop();
        return nullptr;
    }

    return &Session::reader_loop;
}
