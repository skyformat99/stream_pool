#ifndef STREAM_WORKER_QUEUE_STREAM_WORKER_QUEUE_HPP
#define STREAM_WORKER_QUEUE_STREAM_WORKER_QUEUE_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <deque>                             // std::deque
#include <mutex>                             // std::[mutex|lock_guard]
#include <stream_worker/stream_worker.hpp>   // StreamWorker
#include <stream_session/stream_session.hpp> // StreamSession

// stream_worker_queue::node
#include <stream_worker_queue/stream_worker_queue/node.hpp>



// FORWARD DECLARATIONS
// =============================================================================
class StreamWorkerQueue : private std::deque<StreamSession *>
{
public:
    StreamWorkerQueue();
    ~StreamWorkerQueue();


private:



}; // class StreamWorkerQueue

#endif // ifndef STREAM_WORKER_QUEUE_STREAM_WORKER_QUEUE_HPP
