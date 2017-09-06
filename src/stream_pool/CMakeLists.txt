set(STREAM_POOL_HEADERS
    ${STREAM_POOL_INCLUDE_DIR}/stream_pool.hpp)

set(STREAM_POOL_HEADERS
    ${STREAM_POOL_HEADERS}
    PARENT_SCOPE)

# build stream_pool library
add_library(stream_pool stream_pool.cpp ${STREAM_POOL_HEADERS})


if(BUILD_TESTING)
    add_subdirectory(test)
endif()
