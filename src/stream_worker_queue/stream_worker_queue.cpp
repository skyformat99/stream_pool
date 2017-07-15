#include <stream_worker_queue/stream_worker_queue.hpp>



StreamWorkerQueue::StreamWorkerQueue()
{

}


StreamWorkerQueue::~StreamWorkerQueue()
{
    ready.notify_all();

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


Session *
StreamWorkerQueue::dequeue()
{
    std::unique_lock<std::mutex> lock(waiting);
    ready.wait(lock, [this] {
        return finished || !this->empty();
    });

    if (finished)
        return nullptr;

    Session *const session = this->front();
    this->pop_front();
    return session;
}
