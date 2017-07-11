#ifndef STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP
#define STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
// #include <unordered_map>      // std::unordered_map
#include <ostream>            // std::ostream
#include <condition_variable> // std::condition_variable
#include <mutex>              // std::mutex
#include <thread>             // std::thread

#include "blocking_queue/blocking_queue.hpp" // BlockingQueue
#include "stream/stream.hpp"                 // Stream::
#include "stream_pool/stream_pool.hpp"       // StreamPool

#ifdef STREAM_POOL_TESTING_ENABLED
#   include <gtest/gtest.h> // FRIEND_TEST
#endif // ifdef STREAM_POOL_TESTING_ENABLED



// FORWARD DECLARATIONS
// =============================================================================
// class StreamPool;



class StreamSession
{
public:
    StreamSession(const char id,
                  StreamPool *const pool);
    ~StreamSession();


    void process();

private:
    friend std::thread;

    void reader_loop();
    void writer_loop();
    void watchdog_loop();

    std::ostream &log(const char *const function_name);

    const char              id;
    Stream::time_point      timeout;
    std::condition_variable watchdog_event;
    std::mutex              watchdog_lock;
    std::atomic<bool>       keep_alive;
    BlockingQueue           mailbox;
    Stream                  stream;
    StreamPool              *const pool;
}; // class StreamSession

#endif // ifndef STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP
