set(
    STREAM_WORKER_HEADERS
    ${STREAM_WORKER_INCLUDE_DIR}/stream_worker.hpp
    ${STREAM_SESSION_INCLUDE_DIR}/stream_session.hpp
    ${STREAM_WORKER_QUEUE_INCLUDE_DIR}/stream_worker_queue.hpp
)
set(
    sources
    stream_worker.cpp
    ${STREAM_WORKER_HEADERS}
)

# build stream_worker library
add_library(stream_worker ${sources})


if(BUILD_TESTING)
    add_subdirectory(test)
endif()
