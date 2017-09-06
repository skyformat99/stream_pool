#include <stream_worker_queue/stream_worker_queue.hpp>
#include <stream_session/stream_session.hpp>



StreamWorkerQueue::StreamWorkerQueue()
    : finished(false),
      need_partner(false)
{}


StreamWorkerQueue::~StreamWorkerQueue()
{}

void
StreamWorkerQueue::stop()
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
StreamWorkerQueue::enqueue(StreamSession *const session)
{
    {
        std::lock_guard<std::mutex> lock(waiting);

        // if (finished)
        //     return;

        this->emplace_back(session);
    }

    ready.notify_one();
}


StreamSession::Task
StreamWorkerQueue::dequeue(StreamSession *&session)
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
        return &StreamSession::writer_loop;
    }

    need_partner = true;
    partner_ready.wait(lock, [this] {
       return this->finished || !this->need_partner;
    });

    if (finished) {
        session->stop();
        return nullptr;
    }

    return &StreamSession::reader_loop;
}
