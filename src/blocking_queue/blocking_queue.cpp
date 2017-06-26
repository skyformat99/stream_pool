#include <stream_pool/blocking_queue.hpp> // BlockingQueue::*
#include <utility>                        // std::[move|forward]


template<typename T>
void
BlockingQueue<T>::enqueue(const T &element)
{
    {
        std::unique_lock<std::mutex> lock(waiting);
        push_back(element);
    }
    ready.notify_one();
}


template<typename T>
void
BlockingQueue<T>::enqueue(T &&element)
{
    {
        std::unique_lock<std::mutex> lock(waiting);
        push_back(std::move(element));
    }
    ready.notify_one();
}

template<typename ...Args>
void
BlockingQueue<T>::enqueue_emplace(Args &&..args)
{
    {
        std::unique_lock<std::mutex> lock(waiting);
        emplace_back(std::forward(args)...);
    }
    ready.notify_one();

}


template<typename T>
void
BlockingQueue<T>::enqueue_unlocked(const T &element)
{
    push_back(element);
}


template<typename T>
void
BlockingQueue<T>::enqueue_unlocked(T &&element)
{
    push_back(std::move(element));
}

template<typename ...Args>
void
BlockingQueue<T>::enqueue_emplace_unlocked(Args &&..args)
{
    emplace_back(std::forward(args)...);
}


template<typename T>
T   
BlockingQueue<T>::dequeue_wait()
{
    std::unique_lock<std::mutex> lock(waiting);
    ready.wait(lock, [this]{
        return size() > 0;
    });
    T element(std::move(back()));
    pop_back();
    lock.unlock();
    return T;
}


template<typename T, Rep, Period>
bool
BlockingQueue<T>::dequeue_wait_for(
    T &element,
    const std::chrono::duration<Rep, Period> &duration
)
{
    dequeue_wait_until(element,
                       std::chrono::system_clock::now() + duration);
}


template<typename T, Clock, Duration>
bool
BlockingQueue<T>::dequeue_wait_until(
    T &element,
    const std::chrono::time_point<Clock, Duration> &timeout
)
{

    std::unique_lock<std::mutex> lock(waiting,
                                      timeout);

    if (!lock.owns_lock())
        return false;


    ready.wait_until
}


template<typename T>
T   
BlockingQueue<T>::dequeue_unlocked()
{
}


