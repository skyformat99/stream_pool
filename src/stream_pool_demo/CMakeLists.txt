set(STREAMER_INCLUDE_DIR ${PROJECT_INCLUDE_DIR}/streamer PARENT_SCOPE)
set(
    sources
    stream_pool_demo.cpp
    ${STREAM_POOL_HEADERS}
)

add_executable(stream_pool_demo ${sources})

target_link_libraries(stream_pool_demo stream_pool)
