# build stream_pool library
add_library(stream_pool
            stream_pool.cpp
            ${STREAM_POOL_HEADERS}
            $<TARGET_OBJECTS:stream>
            $<TARGET_OBJECTS:stream_session>
            $<TARGET_OBJECTS:stream_worker>
            $<TARGET_OBJECTS:stream_worker_queue>
            $<TARGET_OBJECTS:failure_box>)

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
