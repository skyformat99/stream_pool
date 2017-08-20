include(cpp_restrict_qualifier) # set CPP_RESTRICT_QUALIFIER
include(have_cpp_thread_local)  # set HAVE_CPP_THREAD_LOCAL

# update compile definitions
add_definitions(
    -DCPP_RESTRICT_QUALIFIER=${CPP_RESTRICT_QUALIFIER}
    -DHAVE_CPP_THREAD_LOCAL=${HAVE_CPP_THREAD_LOCAL}
)

# update include path
include_directories(${PROJECT_INCLUDE_DIR})

# executable binaries are output to root 'bin' directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_DIR})

# static and shared libraries are output to root 'lib' directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})

set(STREAM_INCLUDE_DIR              ${PROJECT_INCLUDE_DIR}/stream)
set(STREAM_WORKER_QUEUE_INCLUDE_DIR ${PROJECT_INCLUDE_DIR}/stream_worker_queue)
set(STREAM_WORKER_INCLUDE_DIR       ${PROJECT_INCLUDE_DIR}/stream_worker)
set(STREAM_SESSION_INCLUDE_DIR      ${PROJECT_INCLUDE_DIR}/stream_session)
set(BLOCKING_QUEUE_INCLUDE_DIR      ${PROJECT_INCLUDE_DIR}/blocking_queue)

add_subdirectory(blocking_queue)
add_subdirectory(failure_box)
add_subdirectory(stream)
add_subdirectory(stream_worker_queue)
add_subdirectory(stream_worker)
add_subdirectory(stream_session)
add_subdirectory(stream_pool_demo)
