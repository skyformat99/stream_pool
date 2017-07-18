#include <utility>                           // std::move
#include "stream_session/stream_session.hpp" // StreamSession
#include "stream_pool/stream_pool.hpp"       // StreamPool



static const std::chrono::seconds StreamSession::max_idle(3);


StreamSession::StreamSession(const unsigned char id,
                             StreamPool *const pool)
    : keep_alive(true),
      mailbox(),
      stream(),
      id(id),
      counter(0),
      pool(pool),
      timeout(Stream::now())
{
    pool->start_session(this);
}


~StreamSession::StreamSession()
{}

void
StreamSession::process()
{
    log("process") << "enter" << std::endl;

    mailbox.enqueue_emplace(std::to_string(counter++));

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
        log("writer_loop") << "wrote message" << std::endl;

    log("writer_loop") << "exit" << std::endl;

    keep_alive = false;
}


std::ostream &
StreamSession::log(const char *const function_name)
{
    return std::cout
        << "StreamSession(" << id
                    << ", " << this
                    << ", " << std::this_thread::get_id()
                            << ")::" << function_name << "() -- ";
}
