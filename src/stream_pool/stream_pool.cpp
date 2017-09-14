#include <iostream>                    // std::cout
#include "stream_pool/stream_pool.hpp" // StreamPool::*



// STATIC DATA
// =============================================================================
StreamPool::StreamPool()
    : session_register(),
      ready_sessions(),
      workers {
          { ready_sessions },
          { ready_sessions },
          { ready_sessions },
          { ready_sessions },
          { ready_sessions },
          { ready_sessions },
          { ready_sessions },
          { ready_sessions }
          // StreamWorker(ready_sessions),
          // StreamWorker(ready_sessions),
          // StreamWorker(ready_sessions),
          // StreamWorker(ready_sessions),
          // StreamWorker(ready_sessions),
          // StreamWorker(ready_sessions),
          // StreamWorker(ready_sessions),
          // StreamWorker(ready_sessions)
      }
{
    std::cout << "StreamPool::StreamPool()" << std::endl;
}


StreamPool::~StreamPool()
{
    std::cout << "StreamPool::~StreamPool()" << std::endl;

    stop_sessions();

    ready_sessions.stop();

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
    for (StreamSession::Register::value_type &entry : session_register)
        entry.second.stop();
}

void
StreamPool::route(std::string &&session_id,
                  std::string &&payload)
{
}

void
StreamPool::session_ready(StreamSession *const session)
{
    std::lock_guard<std::mutex> lock(session_register_lock);
    ready_sessions.enqueue(session);
}

void
StreamPool::withdraw(StreamSession::Register::iterator &entry)
{
    session_register.erase(entry);
}
