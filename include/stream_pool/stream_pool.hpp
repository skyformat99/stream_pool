#ifndef STREAM_POOL_STREAM_POOL_HPP
#define STREAM_POOL_STREAM_POOL_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <string>                            // std::string
#include <blocking_queue/blocking_queue.hpp> // BlockingQueue
#include <stream_session/stream_session.hpp> // StreamSession
#include <stream_worker/stream_worker.hpp>   // StreamWorker

#ifdef STREAM_POOL_TESTING_ENABLED
#   include <gtest/gtest.h> // FRIEND_TEST
#endif // ifdef STREAM_POOL_TESTING_ENABLED



class StreamPool
{
public:
    StreamPool();
    ~StreamPool();
    void listen();


private:
    friend StreamSession;
    friend StreamWorker;

    void handle(const std::string &event);
    void start();
    void stop();
    void route(const std::string &id, const std::string &payload);
    void start_session(const std::string &id);
    void stop_session(const std::string &id);

    void withdraw(StreamSession::Record &entry);

    static const std::size_t worker_count;


    StreamSession::Register sessions;
    StreamWorker workers[worker_count];

#ifdef STREAM_POOL_TESTING_ENABLED
    // FRIEND_TEST()
#endif // ifdef STREAM_POOL_TESTING_ENABLED
}; // class StreamPool

#endif // ifndef STREAM_POOL_STREAM_POOL_HPP
