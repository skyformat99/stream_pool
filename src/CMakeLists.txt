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

# header dependencies
set(BLOCKING_QUEUE_HEADERS
    ${PROJECT_INCLUDE_DIR}/blocking_queue/blocking_queue.hpp)

set(FAILURE_BOX_HEADERS
    ${PROJECT_INCLUDE_DIR}/failure_box/failure_box.hpp)

set(STREAM_HEADERS
    ${PROJECT_INCLUDE_DIR}/stream/stream.hpp
    ${BLOCKING_QUEUE_HEADERS}
    ${FAILURE_BOX_HEADERS})

set(STREAM_SESSION_HEADERS
    ${PROJECT_INCLUDE_DIR}/stream_session/stream_session.hpp
    ${BLOCKING_QUEUE_HEADERS}
    ${STREAM_HEADERS})
list(REMOVE_DUPLICATES STREAM_SESSION_HEADERS)

set(STREAM_WORKER_QUEUE_HEADERS
    ${PROJECT_INCLUDE_DIR}/stream_worker_queue/stream_worker_queue.hpp
    ${STREAM_SESSION_HEADERS})

set(STREAM_WORKER_HEADERS
    ${PROJECT_INCLUDE_DIR}/stream_worker/stream_worker.hpp)

set(STREAM_POOL_HEADERS
    ${PROJECT_INCLUDE_DIR}/stream_pool/stream_pool.hpp
    ${BLOCKING_QUEUE_HEADERS}
    ${STREAM_SESSION_HEADERS}
    ${STREAM_WORKER_HEADERS})
list(REMOVE_DUPLICATES STREAM_POOL_HEADERS)


# enter
add_subdirectory(blocking_queue)
add_subdirectory(failure_box)
add_subdirectory(stream)
add_subdirectory(stream_worker_queue)
add_subdirectory(stream_worker)
add_subdirectory(stream_session)
add_subdirectory(stream_pool_demo)
