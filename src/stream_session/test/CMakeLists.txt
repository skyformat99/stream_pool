add_google_test(
    NAME      test_stream_session
    SOURCES   test_stream_session.cpp
              ${STREAM_SESSION_HEADERS}
    LIBRARIES stream_session
)
