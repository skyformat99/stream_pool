set(FAILURE_BOX_INCLUDE_DIR ${PROJECT_INCLUDE_DIR}/failure_box)
set(
    FAILURE_BOX_HEADERS
    ${FAILURE_BOX_INCLUDE_DIR}/failure_box.hpp
)

add_library(failure_box failure_box.cpp ${FAILURE_BOX_HEADERS})

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
