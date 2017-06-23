set(
    sources
    stream_pool.cpp
)

# build stream_pool library
add_library(${STREAM_POOL_LIBRARY} ${sources})


if(BUILD_TESTING)
    add_subdirectory(test)
endif()
