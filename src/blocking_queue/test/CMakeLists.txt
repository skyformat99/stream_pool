include(add_google_test)

add_google_test(
    NAME      test_blocking_queue
    SOURCES   test_blocking_queue.cpp
              ${BLOCKING_QUEUE_HEADERS}
)
