# build stream_worker library

set(headers
    ${STREAM_WORKER_HEADERS}
    ${STREAM_WORKER_QUEUE_HEADERS}
    ${STREAM_SESSION_HEADERS})
list(REMOVE_DUPLICATES headers)

add_library(stream_worker
            stream_worker.cpp
            ${headers})

target_link_libraries(stream_worker
                      stream_worker_queue
                      stream_session)


if(BUILD_TESTING)
    add_subdirectory(test)
endif()
