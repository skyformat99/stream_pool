#ifndef STREAM_POOL_STREAM_STREAM_HPP
#define STREAM_POOL_STREAM_STREAM_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <string>                            // std::string
#include <chrono>                            // std::chrono::*
#include <thread>                            // std::thread
#include <atomic>                            // std::atomic
#include "blocking_queue/blocking_queue.hpp" // BlockingQueue



class Stream : private BlockingQueue<std::string>
{
public:
    Stream();
    ~Stream();
    bool read(std::string &message);
    bool write(std::string &&payload);

private:
    typedef std::chrono::time_point<std::chrono::system_clock> time_point;

    static time_point now();

    static const std::chrono::seconds max_lifespan;
    static const std::chrono::seconds max_downtime;

    std::atomic<bool> continue_writing;
    time_point        idle_timeout;
    const time_point  expiry;
}; // class Stream

#endif // ifndef STREAM_POOL_STREAM_STREAM_HPP
