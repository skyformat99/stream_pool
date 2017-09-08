# build stream_session library
set(headers
    ${STREAM_SESSION_HEADERS}
    ${STREAM_POOL_HEADERS})
list(REMOVE_DUPLICATES headers)

add_library(stream_session
            stream_session.cpp
            ${headers})

target_link_libraries(stream_session
                      PUBLIC blocking_queue
                      PUBLIC stream
                      PUBLIC stream_pool)


if(BUILD_TESTING)
    add_subdirectory(test)
endif()
