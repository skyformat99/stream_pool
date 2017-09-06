set(STREAM_WORKER_HEADERS
    ${STREAM_WORKER_INCLUDE_DIR}/stream_worker.hpp
    ${STREAM_SESSION_INCLUDE_DIR}/stream_session.hpp
    ${STREAM_WORKER_QUEUE_INCLUDE_DIR}/stream_worker_queue.hpp)

set(STREAM_WORKER_HEADERS
    ${STREAM_WORKER_HEADERS}
    PARENT_SCOPE)

# build stream_worker library
add_library(stream_worker stream_worker.cpp ${STREAM_WORKER_HEADERS})


if(BUILD_TESTING)
    add_subdirectory(test)
endif()
