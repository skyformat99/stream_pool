#ifndef STREAM_WORKER_STREAM_WORKER_HPP
#define STREAM_WORKER_STREAM_WORKER_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <thread> // std::thread



// FORWARD DECLARATIONS
// =============================================================================
class StreamPool;


class StreamWorker : private std::thread
{
    StreamWorker(StreamPool *const pool)

}; // class StreamWorker

#endif // ifndef STREAM_WORKER_STREAM_WORKER_HPP
