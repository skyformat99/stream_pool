add_google_test(
    NAME      test_stream_session
    SOURCES   test_stream_session.cpp
              ${STREAM_SESSION_HEADERS}
              $<TARGET_OBJECTS:stream_session>
              $<TARGET_OBJECTS:stream>
)
