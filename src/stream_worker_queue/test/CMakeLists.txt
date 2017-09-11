add_google_test(
    NAME    test_stream_worker_queue
    SOURCES test_stream_worker_queue.cpp
            ${STREAM_WORKER_QUEUE_HEADERS}
            $<TARGET_OBJECTS:stream_worker_queue>
            $<TARGET_OBJECTS:stream_session>
)
