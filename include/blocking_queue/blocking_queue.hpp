#ifndef STREAM_POOL_BLOCKING_QUEUE_BLOCKING_QUEUE_HPP
#define STREAM_POOL_BLOCKING_QUEUE_BLOCKING_QUEUE_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <condition_variable> // std::condition_variable
#include <mutex>              // std::mutex

template<typename T>
class BlockingQueue
{
public:
    BlockingQueue();
    ~BlockingQueue();

private:
    std::mutex              waiting;
    std::condition_variable ready;
    
}; // class BlockingQueue

#endif // ifndef STREAM_POOL_BLOCKING_QUEUE_BLOCKING_QUEUE_HPP
