#include "stream_pool/stream_pool.hpp" // StreamPool::*
#include <iostream>                    // std::cout



// STATIC DATA
// =============================================================================
const std::size_t StreamPool::worker_count = 10;



StreamPool::StreamPool()
    : ouput(std::cout.rdbuf())
{
    ouput << "StreamPool::StreamPool()" << std::endl;

    for (StreamSession &session : sessions)
        session(&output);
}

StreamPool::~StreamPool()
{
    ouput << "StreamPool::~StreamPool()" << std::endl;
}

void
StreamPool::start()
{
}

void
StreamPool::stop_all_sessions()
{

}

void
StreamPool::route(const std::string &session_id,
                  const std::string &payload)
{

}

void
StreamPool::start_session(StreamSession *const session)
{
    starting.enqueue_emplace(session);
}

void
withdraw(StreamSession::Record &entry)
{
    sessions.erase(entry);
}
