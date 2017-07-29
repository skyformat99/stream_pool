add_google_test(
    NAME      test_stream
    SOURCES   test_stream.cpp
              ${STREAM_HEADERS}
    LIBRARIES stream
)
