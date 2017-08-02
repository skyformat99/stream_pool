#ifndef STREAM_POOL_BLOCKING_QUEUE_BLOCKING_QUEUE_HPP
#define STREAM_POOL_BLOCKING_QUEUE_BLOCKING_QUEUE_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <chrono>             // std::chrono::*
#include <deque>              // std::deque
#include <mutex>              // std::[timed_mutex|unique_lock|lock_guard]
#include <condition_variable> // std::condition_variable
#include <utility>            // std::[move|forward]



template<typename T>
class BlockingQueue : public std::deque<T>
{
public:
    // constructors, assignment, destructors all default
    // -------------------------------------------------------------------------
    BlockingQueue()                                      = default;
    BlockingQueue(const BlockingQueue &other)            = default;
    BlockingQueue(BlockingQueue &&other)                 = default;
    BlockingQueue& operator=(const BlockingQueue &other) = default;
    BlockingQueue& operator=(BlockingQueue &&other)      = default;
    ~BlockingQueue()                                     = default;

    // enqueue
    // -------------------------------------------------------------------------
    void
    enqueue(const T &element)
    {
        {
            std::lock_guard<std::timed_mutex> lock(waiting);
            this->push_back(element);
        }
        ready.notify_one();
    }

    void
    enqueue(T &&element)
    {
        {
            std::lock_guard<std::timed_mutex> lock(waiting);
            this->push_back(std::move(element));
        }
        ready.notify_one();
    }

    template<typename ...Args>
    void
    enqueue_emplace(Args &&...args)
    {
        {
            std::lock_guard<std::timed_mutex> lock(waiting);
            this->emplace_back(std::forward(args)...);
        }
        ready.notify_one();
    }

    void
    enqueue_unlocked(const T &element)
    {
        this->push_back(element);
    }

    void
    enqueue_unlocked(T &&element)
    {
        this->push_back(std::move(element));
    }

    template<typename ...Args>
    void
    enqueue_emplace_unlocked(Args &&...args)
    {
        this->emplace_back(std::forward(args)...);
    }

    // dequeue
    // -------------------------------------------------------------------------
    T   
    dequeue_wait()
    {
        std::unique_lock<std::timed_mutex> lock(waiting);
        ready.wait(lock, [this] {
            return !this->empty();
        });

        return dequeue_unlocked();
    }

    template<typename Rep, typename Period>
    bool
    dequeue_wait_for(T &element,
                     const std::chrono::duration<Rep, Period> &duration)
    {
        dequeue_wait_until(element,
                           std::chrono::system_clock::now() + duration);
    }

    template<typename Clock, typename Duration>
    bool
    dequeue_wait_until(T &element,
                       const std::chrono::time_point<Clock, Duration> &timeout)
    {
        bool success;
        std::unique_lock<std::timed_mutex> lock(waiting,
                                                timeout);
        success = lock.owns_lock();

        if (success) {
            success = ready.wait_until(lock, timeout, [this] {
                return !this->empty();
            });

            if (success) {
                element = std::move(this->front());
                this->pop_front();
            }
        }

        return success;
    }

    T   
    dequeue_unlocked()
    {
        T element(std::move(this->front()));
        this->pop_front();
        return element;
    }


private:
    std::timed_mutex        waiting;
    std::condition_variable ready;
}; // class BlockingQueue

#endif // ifndef STREAM_POOL_BLOCKING_QUEUE_BLOCKING_QUEUE_HPP
