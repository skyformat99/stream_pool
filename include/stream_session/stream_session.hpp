#ifndef STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP
#define STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
// #include <unordered_map>      // std::unordered_map
#include <chrono>             // std::chrono::*
#include <condition_variable> // std::condition_variable
#include <mutex>              // std::mutex
#include <thread>             // std::thread

#include "stream_pool/stream/stream.hpp" // Stream

#ifdef STREAM_POOL_TESTING_ENABLED
#   include <gtest/gtest.h> // FRIEND_TEST
#endif // ifdef STREAM_POOL_TESTING_ENABLED



// FORWARD DECLARATIONS
// =============================================================================
// class StreamPool;



class StreamSession
{
    friend class StreamPool;

private:
    typedef Register::iterator Record;


    StreamSession();
    ~StreamSession();


    void process();
    void stop();

    void reader_loop();
    void writer_loop();
    void watchdog_loop();


    std::chrono::time_point<std::chrono::system_clock>
    std::condition_variable watchdog_event;
    std::mutex              watchdog_lock;
    Record                  enrollment;
    Stream                  stream;
}; // class StreamSession

#endif // ifndef STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP
