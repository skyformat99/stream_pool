set(STREAM_SESSION_HEADERS
    ${PROJECT_INCLUDE_DIR}/stream_session/stream_session.hpp)
set(STREAM_SESSION_HEADERS
    ${STREAM_SESSION_HEADERS}
    PARENT_SCOPE)


# build stream_session library
add_library(stream_session stream_session.cpp ${STREAM_SESSION_HEADERS})


if(BUILD_TESTING)
    add_subdirectory(test)
endif()
