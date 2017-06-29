#ifndef STREAM_POOL_STREAM_STREAM_HPP
#define STREAM_POOL_STREAM_STREAM_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <string>                            // std::string
#include <chrono>                            // std::chrono::*
#include <thread>                            // std::thread
#include "blocking_queue/blocking_queue.hpp" // BlockingQueue



class Stream : private BlockingQueue
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

    time_point last_read;
    const time_point expiry;
}; // class Stream

#endif // ifndef STREAM_POOL_STREAM_STREAM_HPP
