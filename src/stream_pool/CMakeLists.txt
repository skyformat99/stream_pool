set(STREAM_POOL_INCLUDE_DIR ${PROJECT_INCLUDE_DIR}/stream_pool)
set(
    sources
    stream_pool.cpp
    ${STREAM_POOL_INCLUDE_DIR}/stream_pool.hpp
)

# build stream_pool library
add_library(stream_pool ${sources})


if(BUILD_TESTING)
    add_subdirectory(test)
endif()
