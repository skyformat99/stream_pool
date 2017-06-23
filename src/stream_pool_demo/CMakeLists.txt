set(
    sources
    stream_pool_demo.cpp
    ${STREAM_POOL_HEADERS}
)

add_executable(stream_pool_demo ${sources})
target_link_libraries(stream_pool_demo ${STREAM_POOL_LIBRARY})
