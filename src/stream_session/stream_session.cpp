#include <iostream>                          // std::cout
#include <utility>                           // std::move
#include "stream_session/stream_session.hpp" // StreamSession
#include "stream_pool/stream_pool.hpp"       // StreamPool



const std::chrono::seconds StreamSession::max_idle(3);


StreamSession::StreamSession()
{}

StreamSession::~StreamSession()
{}

void
StreamSession::start(StreamSession::Register::iterator &entry,
                     StreamPool *const pool)
{
    this->keep_alive = true;
    this->entry      = entry;
    this->pool       = pool;
    this->stream.start();
    pool->session_ready(this);
}

void
StreamSession::process(std::string &&message)
{
    log("process") << "enter" << std::endl;

    mailbox.enqueue_emplace(message);

    log("process") << "exit" << std::endl;
}

void
StreamSession::stop()
{
    keep_alive = false;
}


void
StreamSession::reader_loop()
{
    std::string message;

    log("reader_loop") << "enter" << std::endl;

    while (   keep_alive
           && stream.read(message))
        log("reader_loop") << "read message: " << message << std::endl;

    log("reader_loop") << "exit" << std::endl;

    keep_alive = false;
}


void
StreamSession::writer_loop()
{
    std::string message;

    log("writer_loop") << "enter" << std::endl;

    while (   keep_alive
           && mailbox.dequeue_wait_for(message,
                                       max_idle)
           && keep_alive
           && stream.write(std::move(message)))
        log("writer_loop") << "wrote message (" << counter++ <<  ')' << std::endl;

    log("writer_loop") << "exit" << std::endl;

    keep_alive = false;
}


std::ostream &
StreamSession::log(const char *const function_name)
{
    return std::cout
        << "StreamSession(session_id=" << entry->first // session_id
                    << ", this="       << this
                    << ", thread_id="  << std::this_thread::get_id()
                            << ")::" << function_name << "() -- ";
}
