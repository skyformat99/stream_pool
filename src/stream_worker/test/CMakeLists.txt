add_google_test(
    NAME    test_stream_worker
    SOURCES test_stream_worker.cpp
            ${STREAM_WORKER_HEADERS}
            $<TARGET_OBJECTS:stream_worker>
            $<TARGET_OBJECTS:stream_worker_queue>
            $<TARGET_OBJECTS:stream_session>
)
