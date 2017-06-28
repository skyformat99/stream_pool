#ifndef STREAM_POOL_STREAM_STREAM_HPP
#define STREAM_POOL_STREAM_STREAM_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <string>                            // std::string
#include <chrono>                            // std::chrono::*
#include <thread>                            // std::thread
#include "blocking_queue/blocking_queue.hpp" // BlockingQueue



// FORWARD DECLARATIONS
// =============================================================================
// class StreamPool;



class Stream : private BlockingQueue
{
public:
    Stream();
    ~Stream();
    bool read(std::string &message);
    bool write(std::string &&payload);

private:
    static const std::chrono::seconds max_lifespan(15);
    static const std::chrono::seconds max_downtime(5);

    std::chrono::time_point<std::chrono::system_clock> last_read;
    const std::chrono::time_point<std::chrono::system_clock> expiry;
}; // class Stream

#endif // ifndef STREAM_POOL_STREAM_STREAM_HPP
