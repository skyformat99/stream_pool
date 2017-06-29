#include "stream/stream.hpp"



// STATIC DATA
// =============================================================================
static const std::chrono::seconds Stream::max_lifespan(15);
static const std::chrono::seconds Stream::max_downtime(5);


Stream::Stream()
    : last_read(time_point::max()),
      expiry(now() + max_lifespan)
{}


bool
Stream::read(std::string &message)
{
    return false;
}


bool
Stream::write(std::string &&payload)
{
    return false;
}


Stream::time_point
Stream::now()
{
    return std::chrono::system_clock::now();
}
