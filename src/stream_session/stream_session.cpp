#include "stream_session/stream_session.hpp" // StreamSession



StreamSession::StreamSession(StreamPool *const pool)
    : watchdog_lock(),
      watchdog_event(),
      keep_alive(true),
      mailbox(),
      stream(),
      pool(pool),
{
}

~StreamSession();
