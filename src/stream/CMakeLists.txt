set(STREAMER_INCLUDE_DIR ${PROJECT_INCLUDE_DIR}/streamer)
set(
    STREAMER_HEADERS
    ${STREAMER_INCLUDE_DIR}/streamer.hpp
)

add_library(streamer streamer.cpp ${STREAMER_HEADERS})

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
