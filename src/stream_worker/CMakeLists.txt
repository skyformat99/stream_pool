# build stream_worker library

set(headers
    ${STREAM_WORKER_HEADERS}
    ${STREAM_WORKER_QUEUE_HEADERS}
    ${STREAM_SESSION_HEADERS})
list(REMOVE_DUPLICATES headers)

add_library(stream_worker OBJECT
            stream_worker.cpp
            ${headers})

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
