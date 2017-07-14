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
}
