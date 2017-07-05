#ifndef STREAM_POOL_STREAM_STREAM_HPP
#define STREAM_POOL_STREAM_STREAM_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <string>                            // std::string
#include <chrono>                            // std::chrono::*
#include <thread>                            // std::thread
#include <atomic>                            // std::atomic
#include <random>                            // std::[random_device
                                             //      |default_random_engine
                                             //      |uniform_int_distribution]
#include "blocking_queue/blocking_queue.hpp" // BlockingQueue



class Stream : private BlockingQueue<std::string>
{
public:
    Stream();
    ~Stream();
    bool start();
    bool read(std::string &message);
    bool write(std::string &&payload);

private:
    typedef std::chrono::time_point<std::chrono::system_clock> time_point;
    typedef unsigned int                                       outcome_type;

    static const std::chrono::seconds max_lifespan;
    static const std::chrono::seconds max_downtime;
    static std::random_device         random_seed;
    static const outcome_type         outcome_min;
    static const outcome_type         outcome_max;
    static const outcome_type         outcome_fail;

    static time_point now();

    std::default_random_engine                  random_engine;
    std::uniform_int_distribution<outcome_type> distribution;
    std::atomic<bool>                           continue_writing;
    time_point                                  idle_timeout;
    const time_point                            expiry;
}; // class Stream

#endif // ifndef STREAM_POOL_STREAM_STREAM_HPP
