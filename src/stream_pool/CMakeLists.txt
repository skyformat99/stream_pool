# build stream_pool library
add_library(stream_pool
            stream_pool.cpp
            ${STREAM_POOL_HEADERS})

target_link_libraries(stream_pool
                      PUBLIC blocking_queue
                      PUBLIC stream_session
                      PUBLIC stream_worker)

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
