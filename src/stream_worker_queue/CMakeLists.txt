set(
    STREAM_WORKER_HEADERS
    ${STREAM_INCLUDE_DIR}/stream_worker_queue.hpp
)

add_library(stream_worker_queue stream_worker_queue.cpp ${STREAM_WORKER_HEADERS})

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
