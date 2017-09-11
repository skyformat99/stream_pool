add_library(stream OBJECT
            stream.cpp
            ${STREAM_HEADERS})

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
