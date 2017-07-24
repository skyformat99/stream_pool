#include <functional>                                  // std::ref
#include <stream_worker_queue/stream_worker_queue.hpp> // StreamWorkerQueue
#include <stream_worker/stream_worker.hpp>             // StreamWorker



StreamWorker::StreamWorker(StreamWorkerQueue &schedule)
    : std::thread(&loop,
                  std::ref(schedule))
{}


StreamWorker::~StreamWorker()
{}


void
loop(StreamWorkerQueue &schedule)
{
    StreamSession *session;
    void (StreamSession::*task)();

    while (task = schedule.dequeue(session))
        session->*task();
}
