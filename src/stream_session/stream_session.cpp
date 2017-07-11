#include "stream_session/stream_session.hpp" // StreamSession



StreamSession::StreamSession(const char id,
                             StreamPool *const pool)
    : watchdog_lock(),
      watchdog_event(),
      keep_alive(true),
      mailbox(),
      stream(),
      id(id),
      pool(pool),
      timeout(Stream::now())
{
    pool->start_session(this);
}


~StreamSession::StreamSession()
{}


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

std::ostream &
StreamSession::log(const char *const function_name)
{
    return std::cout
        << "StreamSession(" << id
                    << ", " << this
                    << ", " << std::this_thread::get_id()
                            << ")::" << function_name << "() -- ";
}
