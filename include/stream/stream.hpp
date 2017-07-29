
// EXTERNAL DEPENDENCIES
// =============================================================================
#include <string>                            // std::string
#include <chrono>                            // std::chrono::*
#include <thread>                            // std::thread
#include <atomic>                            // std::atomic
#include "blocking_queue/blocking_queue.hpp" // BlockingQueue
#include "failure_box/failure_box.hpp"       // FailureBox
#include "stream_common/stream_common.hpp"   // FailureBox



class Stream : private BlockingQueue<std::string>
{
public:
    typedef std::chrono::time_point<std::chrono::system_clock> time_point;

    Stream();
    ~Stream();
    bool start();
    bool read(std::string &message);
    bool write(std::string &&payload);

    static time_point now();

private:
    static const std::chrono::seconds max_lifespan;
    static const std::chrono::seconds max_downtime;
    static const unsigned int         expected_query_lifespan;

    std::atomic<bool> continue_writing;
    time_point        idle_timeout;
    const time_point  expiry;
    FailureBox        failure_box;
}; // class Stream

#endif // ifndef STREAM_POOL_STREAM_STREAM_HPP
