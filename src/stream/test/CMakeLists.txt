add_google_test(
    NAME    test_stream
    SOURCES test_stream.cpp
            ${STREAM_HEADERS}
            $<TARGET_OBJECTS:stream>
            $<TARGET_OBJECTS:failure_box>
)
