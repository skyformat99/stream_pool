set(STREAM_SESSION_INCLUDE_DIR ${PROJECT_INCLUDE_DIR}/stream_session)
set(
    STREAM_SESSION_HEADERS
    ${STREAM_SESSION_INCLUDE_DIR}/stream_session.hpp
)
set(
    sources
    stream_session.cpp
    ${STREAM_SESSION_HEADERS}
)

# build stream_session library
add_library(stream_session ${sources})


if(BUILD_TESTING)
    add_subdirectory(test)
endif()
