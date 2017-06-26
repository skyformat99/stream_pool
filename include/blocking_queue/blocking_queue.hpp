#ifndef STREAM_POOL_BLOCKING_QUEUE_BLOCKING_QUEUE_HPP
#define STREAM_POOL_BLOCKING_QUEUE_BLOCKING_QUEUE_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <deque>              // std::deque
#include <mutex>              // std::mutex
#include <condition_variable> // std::condition_variable



template<typename T>
class BlockingQueue : std::deque<T>
{
public:
    // constructors, assignment, destructors all default
    BlockingQueue()                                      = default;
    BlockingQueue(const BlockingQueue &other)            = default;
    BlockingQueue(BlockingQueue &&other)                 = default;
    BlockingQueue& operator=(const BlockingQueue &other) = default;
    BlockingQueue& operator=(BlockingQueue &&other)      = default;
    ~BlockingQueue()                                     = default;

    // enqueue
    void enqueue(const T &element);
    void enqueue(T &&element);
    template<typename ...Args>
    void enqueue_emplace(Args &&..args);
    void enqueue_unlocked(const T &element);
    void enqueue_unlocked(T &&element);
    template<typename ...Args>
    void enqueue_emplace_unlocked(Args &&..args);

    // dequeue
    T dequeue_wait();
    template<typename Rep, Period>
    bool dequeue_wait_for(T &element,
                          const std::chrono::duration<Rep, Period> &duration);
    template<typename Clock, Duration>
    bool dequeue_wait_until(
        T &element,
        const std::chrono::time_point<Clock, Duration> &timeout
    );
    T dequeue_unlocked();


private:
    std::mutex              waiting;
    std::condition_variable blocked;
}; // class BlockingQueue

#endif // ifndef STREAM_POOL_BLOCKING_QUEUE_BLOCKING_QUEUE_HPP
