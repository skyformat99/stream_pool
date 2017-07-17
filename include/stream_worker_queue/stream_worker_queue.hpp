#ifndef STREAM_WORKER_QUEUE_STREAM_WORKER_QUEUE_HPP
#define STREAM_WORKER_QUEUE_STREAM_WORKER_QUEUE_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <deque>              // std::deque
#include <atomic>             // std::atomic
#include <mutex>              // std::[mutex|lock_guard]
#include <condition_variable> // std::condition_variable



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

    void (StreamSession::*)()
    dequeue(StreamSession *&session);


private:
    std::atomic<bool>       finished;
    std::mutex              waiting;
    std::condition_variable ready;
    bool                    need_partner;
    std::condition_variable partner_ready;
}; // class StreamWorkerQueue

#endif // ifndef STREAM_WORKER_QUEUE_STREAM_WORKER_QUEUE_HPP
