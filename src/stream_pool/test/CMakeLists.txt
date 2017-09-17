add_custom_command(
    TARGET copy_test
    PRE_LINK
    COMMAND ${CMAKE_COMMAND} -e copy_directory ooga booga
)
foreach(test_name constructors)
    add_google_test(
        NAME      test_stream_pool_${test_name}
        SOURCES   test_stream_pool_${test_name}.cpp
                  ${STREAM_POOL_HEADERS}
        LIBRARIES stream_pool
    )

    add_dependencies(test_stream_pool_${test_name}
                     copy_test)
endforeach()
