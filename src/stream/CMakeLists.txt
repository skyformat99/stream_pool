set(STREAM_INCLUDE_DIR ${PROJECT_INCLUDE_DIR}/stream)
set(
    STREAM_HEADERS
    ${STREAM_INCLUDE_DIR}/stream.hpp
)

add_library(stream stream.cpp ${STREAM_HEADERS})

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
