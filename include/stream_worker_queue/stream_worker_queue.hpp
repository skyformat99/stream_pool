#ifndef STREAM_WORKER_QUEUE_STREAM_WORKER_QUEUE_HPP
#define STREAM_WORKER_QUEUE_STREAM_WORKER_QUEUE_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <deque>                             // std::deque
#include <mutex>                             // std::[mutex|lock_guard]
#include <blocking_queue/blocking_queue.hpp> // BlockingQueue
#include <stream_worker/stream_worker.hpp>   // StreamWorker



// FORWARD DECLARATIONS
// =============================================================================

class StreamWorkerQueue : private std::deque<StreamWorkerQueue::Node>
{
public:
    StreamWorkerQueue();
    ~StreamWorkerQueue();

    

private:
}; // class StreamWorkerQueue

#endif // ifndef STREAM_WORKER_QUEUE_STREAM_WORKER_QUEUE_HPP
