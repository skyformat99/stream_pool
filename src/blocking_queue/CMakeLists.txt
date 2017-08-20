set(
    BLOCKING_QUEUE_HEADERS
    ${BLOCKING_QUEUE_INCLUDE_DIR}/blocking_queue.hpp
)

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
