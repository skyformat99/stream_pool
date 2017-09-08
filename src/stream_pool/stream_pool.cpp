#include <iostream>                    // std::cout
#include "stream_pool/stream_pool.hpp" // StreamPool::*



// STATIC DATA
// =============================================================================
StreamPool::StreamPool()
    : sessions(),
      ready_sessions(),
      workers {
          StreamWorker(ready_sessions),
          StreamWorker(ready_sessions),
          StreamWorker(ready_sessions),
          StreamWorker(ready_sessions),
          StreamWorker(ready_sessions),
          StreamWorker(ready_sessions),
          StreamWorker(ready_sessions),
          StreamWorker(ready_sessions)
      }
{
    std::cout << "StreamPool::StreamPool()" << std::endl;
}


StreamPool::~StreamPool()
{
    std::cout << "StreamPool::~StreamPool()" << std::endl;

    stop_sessions();

    starting_sessions.stop();

    for (StreamWorker &worker : workers)
        worker.join();
}


void
StreamPool::listen()
{
    std::string input;
    std::string payload;
    std::string::size_type i_split;

    while (std::getline(std::cin, input)) {
        i_split = input.find(':');

        if (i_split == std::string::npos) {
            if (input == "stop")
                break;

            if (input == "stop_sessions") {
                stop_sessions();
                continue;
            }

            // input == session_id
            payload = "DEFAULT MESSAGE";

        } else {
            payload = input.substr(i_split);
            input.resize(i_split - (i_split > 0));
        }

        route(std::move(input), // session_id
              std::move(payload));
    }
}


void
StreamPool::stop_sessions()
{
    for (StreamSession::Register::iterator entry : session_register)
        entry->second.stop();
}

void
StreamPool::route(std::string &&session_id,
                  std::string &&payload)
{

}

void
StreamPool::session_ready(StreamSession *const session)
{
    starting_sessions.enqueue_emplace(session);
}

void
withdraw(StreamSession::Record &entry)
{
    sessions.erase(entry);
}
