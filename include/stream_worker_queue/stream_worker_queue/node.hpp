#ifndef STREAM_WORKER_QUEUE_STREAM_WORKER_QUEUE_NODE_HPP
#define STREAM_WORKER_QUEUE_STREAM_WORKER_QUEUE_NODE_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <deque>                             // std::deque
#include <mutex>                             // std::[mutex|lock_guard]
#include <blocking_queue/blocking_queue.hpp> // BlockingQueue
#include <stream_worker/stream_worker.hpp>   // StreamWorker

namespace stream_worker_queue {

class Node
{
public:
    Node(StreamSession *session);

    ~Node();

private:

    
}; // class Node

} // namespace stream_worker_queue

#endif // ifndef STREAM_WORKER_QUEUE_STREAM_WORKER_QUEUE_NODE_HPP
