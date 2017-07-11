#include <utility>           // std::move
#include "stream/stream.hpp" // Stream::*



// STATIC DATA
// =============================================================================
static const std::chrono::seconds Stream::max_lifespan(15);
static const std::chrono::seconds Stream::max_downtime(5);

// fail roughly 1 in 100 queries
static const unsigned int Stream::expected_query_lifespan(100);


Stream::Stream()
    : continue_writing(true),
      failure_box(expected_query_lifespan),
      idle_timeout(time_point::max()),
      expiry(now() + max_lifespan)
{}


bool
Stream::read(std::string &message)
{
    const std::chrono::seconds &timeout = std::min(idle_timeout,
                                                   expiry);

    const bool success = failure_box.query()
                      && dequeue_wait_for(message,
                                          timedout);
    if (!success)
        continue_writing = false; // make sure not to reset to true

    return success;
}


bool
Stream::write(std::string &&payload)
{
    const bool success = failure_box.query()
                      && continue_writing;

    if (success)
        enqueue(std::move(payload));

    return success;
}


Stream::time_point
Stream::now()
{
    return std::chrono::system_clock::now();
}
