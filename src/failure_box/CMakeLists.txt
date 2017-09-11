add_library(failure_box OBJECT
            failure_box.cpp
            ${FAILURE_BOX_HEADERS})

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
