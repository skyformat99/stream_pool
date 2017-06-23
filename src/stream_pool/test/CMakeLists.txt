include(add_google_test)

foreach(test_name constructors)
    add_google_test(
        NAME      test_stream_pool_${test_name}
        SOURCES   test_stream_pool_${test_name}.cpp
                  ${STREAM_POOL_HEADERS}
        LIBRARIES ${STREAM_POOL_LIBRARY}
    )
endforeach()
