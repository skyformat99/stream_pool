set(
    STREAM_POOL_HEADERS
    ${STREAM_POOL_INCLUDE_DIR}/stream_pool.hpp
)
set(
    sources
    stream_pool.cpp
    ${STREAM_POOL_HEADERS}
)

# build stream_pool library
add_library(stream_pool ${sources})


if(BUILD_TESTING)
    add_subdirectory(test)
endif()
