#ifndef STREAM_WORKER_QUEUE_STREAM_WORKER_QUEUE_HPP
#define STREAM_WORKER_QUEUE_STREAM_WORKER_QUEUE_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <deque>                             // std::deque
#include <mutex>                             // std::[mutex|lock_guard]
#include <condition_variable>                // std::condition_variable



// FORWARD DECLARATIONS
// =============================================================================
class StreamSession;


class StreamWorkerQueue : private std::deque<StreamSession *>
{
public:
    StreamWorkerQueue();
    ~StreamWorkerQueue();

    void
    enqueue(StreamSession *const session);

    Session *
    dequeue();
    {
        {
            std::lock_guard<std::mutex> lock(waiting);
            this->emplace_back(session);
        }
        ready.notify_one();
    }

private:
    std::mutex              waiting;
    std::condition_variable ready;
}; // class StreamWorkerQueue

#endif // ifndef STREAM_WORKER_QUEUE_STREAM_WORKER_QUEUE_HPP
