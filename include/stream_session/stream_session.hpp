#ifndef STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP
#define STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
// #include <unordered_map>      // std::unordered_map
#include <ostream>            // std::ostream
#include <thread>             // std::thread
#include <chrono>             // std::chrono

#include "blocking_queue/blocking_queue.hpp" // BlockingQueue
#include "stream/stream.hpp"                 // Stream::

#ifdef STREAM_POOL_TESTING_ENABLED
#   include <gtest/gtest.h> // FRIEND_TEST
#endif // ifdef STREAM_POOL_TESTING_ENABLED



// FORWARD DECLARATIONS
// =============================================================================
class StreamPool;



class StreamSession
{
public:
    StreamSession(const char id,
                  StreamPool *const pool);
    ~StreamSession();


    void process();
    void stop();

private:
    friend std::thread;

    void reader_loop();
    void writer_loop();

    std::ostream &log(const char *const function_name);

    const char                 id;
    unsigned int               counter;
    Stream::time_point         timeout;
    std::atomic<bool>          keep_alive;
    BlockingQueue<std::string> mailbox;
    Stream                     stream;
    StreamPool          *const pool;
}; // class StreamSession

#endif // ifndef STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP
