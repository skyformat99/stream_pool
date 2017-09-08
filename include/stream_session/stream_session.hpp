#ifndef STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP
#define STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <map>      // std::map (iterators must remain valid throughout mods)
#include <ostream>  // std::ostream
// #include <thread>   // std::thread
#include <chrono>   // std::chrono

#include "blocking_queue/blocking_queue.hpp" // BlockingQueue
#include "stream/stream.hpp"                 // Stream

#ifdef STREAM_POOL_TESTING_ENABLED
#   include <gtest/gtest.h> // FRIEND_TEST
#endif // ifdef STREAM_POOL_TESTING_ENABLED



// FORWARD DECLARATIONS
// =============================================================================
class StreamPool;



class StreamSession
{
public:
    typedef std::map<std::string, StreamSession> Register;
    typedef void (StreamSession::*Task)();

    StreamSession();
    ~StreamSession();

    void process(std::string &&message);
    void start(Register::iterator &entry,
               StreamPool *const pool);
    void stop();

private:
    // friend std::thread;
    friend class StreamWorkerQueue;

    // 'Task's
    void reader_loop();
    void writer_loop();

    std::ostream &log(const char *const function_name);

    unsigned int               counter;
    std::atomic<bool>          keep_alive;
    BlockingQueue<std::string> mailbox;
    Stream                     stream;
    Register::iterator         entry;
    StreamPool          *const pool;
}; // class StreamSession

#endif // ifndef STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP
