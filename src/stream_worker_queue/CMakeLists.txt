set(headers
    ${STREAM_WORKER_QUEUE_HEADERS}
    ${STREAM_SESSION_HEADERS})
list(REMOVE_DUPLICATES headers)

add_library(stream_worker_queue
            stream_worker_queue.cpp
            ${headers})

target_link_libraries(stream_worker_queue
                      PUBLIC stream_session)

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
