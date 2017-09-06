add_executable(stream_pool_demo stream_pool_demo.cpp ${STREAM_POOL_HEADERS})

target_link_libraries(stream_pool_demo stream_pool)
