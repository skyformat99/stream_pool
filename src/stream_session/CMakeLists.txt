# build stream_session library
set(headers
    ${STREAM_SESSION_HEADERS}
    ${STREAM_POOL_HEADERS})
list(REMOVE_DUPLICATES headers)

add_library(stream_session OBJECT
            stream_session.cpp
            ${headers})

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
