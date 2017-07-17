#include <stream_worker_queue/stream_worker_queue.hpp>
#include <stream_session/stream_session.hpp>



StreamWorkerQueue::StreamWorkerQueue()
    finished(false)
{

}


StreamWorkerQueue::~StreamWorkerQueue()
{
    finished = true;
    ready.notify_all();
    partner_ready.notify_one();
}


void
StreamWorkerQueue::enqueue(StreamSession *const session)
{
    {
        std::lock_guard<std::mutex> lock(waiting);
        this->emplace_back(session);
    }

    ready.notify_one();
}


void (StreamSession::*)()
StreamWorkerQueue::dequeue(StreamSession *&session)
{
    if (finished)
        return nullptr;

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

    lock.unlock();

    if (finished) {
        session->stop();
        return nullptr;
    }

    return &Session::reader_loop;
}
