#ifndef STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP
#define STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
// #include <unordered_map>      // std::unordered_map
#include <string>             // std::string
#include <chrono>             // std::chrono::*
#include <condition_variable> // std::condition_variable
#include <mutex>              // std::mutex



// FORWARD DECLARATIONS
// =============================================================================
// class StreamPool;



class StreamSession
{
public:
    StreamSession()
    {

    }

private:
    // friend StreamPool;

    typedef std::unordered_map<std::string, StreamSession> Register;
    typedef Register::iterator Record;



    StreamSession();
    ~StreamSession();


    void process(const std::string &payload);
    void stop();

    void reader_loop();
    void writer_loop();
    void watchdog_loop();


    std::chrono::time_point<std::chrono::system_clock>
    std::condition_variable watchdog_event;
    std::mutex              watchdog_lock;
    Record                  enrollment;
}; // class StreamSession

#endif // ifndef STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP
