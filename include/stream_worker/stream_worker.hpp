#ifndef STREAM_WORKER_STREAM_WORKER_HPP
#define STREAM_WORKER_STREAM_WORKER_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <thread> // std::thread



// FORWARD DECLARATIONS
// =============================================================================
class StreamWorkerQueue;


class StreamWorker : public std::thread
{
public:
    StreamWorker(StreamWorkerQueue &schedule);
    StreamWorker();
    ~StreamWorker();

    static void
    loop(StreamWorkerQueue &schedule);
}; // class StreamWorker

#endif // ifndef STREAM_WORKER_STREAM_WORKER_HPP
