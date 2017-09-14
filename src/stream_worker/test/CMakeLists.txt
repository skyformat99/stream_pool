add_google_test(
    NAME      test_stream_worker
    SOURCES   test_stream_worker.cpp
              ${STREAM_WORKER_HEADERS}
    LIBRARIES stream_pool
)
