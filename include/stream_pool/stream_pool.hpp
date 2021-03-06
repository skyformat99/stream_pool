#ifndef STREAM_POOL_STREAM_POOL_HPP
#define STREAM_POOL_STREAM_POOL_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <string>                                      // std::string
#include <atomic>                                      // std::atomic
#include "stream_session/stream_session.hpp"           // StreamSession
#include "stream_worker/stream_worker.hpp"             // StreamWorker
#include "stream_worker_queue/stream_worker_queue.hpp" // StreamWorkerQueue

#ifdef BUILD_TESTING
#   include <gtest/gtest.h>                       // FRIEND_TEST
#else
#   define FRIEND_TEST(TEST_CASE_NAME, TEST_NAME) // disable
#endif // ifdef BUILD_TESTING



class StreamPool
{
public:
    StreamPool();
    ~StreamPool();
    void listen();


private:
    friend class StreamSession;

    void handle(const std::string &event);
    void stop_sessions();
    void route(std::string &&session_id,
               std::string &&payload);

    void session_ready(StreamSession *const session);

    void stop_session(const std::string &id);

    void withdraw(StreamSession::Register::iterator &entry);

    std::atomic<bool>       sessions_
    std::mutex              session_register_lock;
    StreamSession::Register session_register;
    StreamWorkerQueue       ready_sessions;
    StreamWorker            workers[8];
}; // class StreamPool

#endif // ifndef STREAM_POOL_STREAM_POOL_HPP
