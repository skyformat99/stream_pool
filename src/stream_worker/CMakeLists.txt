# build stream_worker library
add_library(stream_worker
            stream_worker.cpp
            ${STREAM_WORKER_HEADERS}
            ${STREAM_SESSION_HEADERS}
            ${STREAM_WORKER_QUEUE_HEADERS})


if(BUILD_TESTING)
    add_subdirectory(test)
endif()
