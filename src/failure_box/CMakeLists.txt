set(
    FAILURE_BOX_HEADERS
    ${PROJECT_INCLUDE_DIR}/failure_box/failure_box.hpp
    PARENT_SCOPE
)

add_library(failure_box failure_box.cpp ${FAILURE_BOX_HEADERS})

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
