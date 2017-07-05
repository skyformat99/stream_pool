include(cpp_restrict_qualifier) # set CPP_RESTRICT_QUALIFIER

# update compile definitions
add_definitions(-DCPP_RESTRICT_QUALIFIER=${CPP_RESTRICT_QUALIFIER})

# update include path
include_directories(${PROJECT_INCLUDE_DIR})

# executable binaries are output to root 'bin' directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_DIR})

# static and shared libraries are output to root 'lib' directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})


add_subdirectory(blocking_queue)
add_subdirectory(failure_box)
# add_subdirectory(stream_pool)
# add_subdirectory(stream_pool_demo)
