#ifndef STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP
#define STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <unordered_map>      // std::unordered_map
#include <string>             // std::string
#include <chrono>             // std::chrono::seconds
#include <condition_variable> // std::condition_variable
#include <mutex>              // std::mutex

#ifdef STREAM_POOL_TESTING_ENABLED
#   include <gtest/gtest.h> // FRIEND_TEST
#endif // ifdef STREAM_POOL_TESTING_ENABLED



// FORWARD DECLARATIONS
// =============================================================================
class StreamPool;



class StreamSession
{
private:
    friend StreamPool;

    typedef std::unordered_map<std::string, StreamSession> Register;
    typedef Register::iterator Record;



    StreamSession();
    ~StreamSession();


    void start();
    void stop();

    void reader_loop();
    void writer_loop();
    void watchdog_loop();


    static const std::chrono::seconds time_limit(20);

    std::condition_variable watchdog_event;
    std::mutex              watchdog_lock;
    Record                  enrollment;
}; // class StreamSession

#endif // ifndef STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP
