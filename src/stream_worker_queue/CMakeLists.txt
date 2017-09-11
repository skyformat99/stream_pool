set(headers
    ${STREAM_WORKER_QUEUE_HEADERS}
    ${STREAM_SESSION_HEADERS})
list(REMOVE_DUPLICATES headers)

add_library(stream_worker_queue OBJECT
            stream_worker_queue.cpp
            ${headers})

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
