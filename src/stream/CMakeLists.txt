add_library(stream
            stream.cpp
            ${STREAM_HEADERS})

target_link_libraries(stream
                      PUBLIC failure_box)

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
