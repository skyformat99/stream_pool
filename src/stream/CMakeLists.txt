set(STREAM_HEADERS
    ${STREAM_INCLUDE_DIR}/stream.hpp)

set(STREAM_HEADERS
    ${STREAM_HEADERS}
    PARENT_SCOPE)

add_library(stream stream.cpp ${STREAM_HEADERS})

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
