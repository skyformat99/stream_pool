add_google_test(
    NAME      test_failure_box
    SOURCES   test_failure_box.cpp
              ${FAILURE_BOX_HEADERS}
    LIBRARIES failure_box
)
