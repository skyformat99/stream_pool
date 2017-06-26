set(BLOCKING_QUEUE_INCLUDE_DIR ${PROJECT_INCLUDE_DIR}/blocking_queue)
set(
    BLOCKING_QUEUE_HEADERS
    ${BLOCKING_QUEUE_INCLUDE_DIR}/blocking_queue.hpp
)
set(
    sources
    blocking_queue.cpp
    ${BLOCKING_QUEUE_HEADERS}
)


# build blocking_queue library
add_library(blocking_queue ${sources})


if(BUILD_TESTING)
    add_subdirectory(test)
endif()
