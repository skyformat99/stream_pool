#ifndef FAILURE_BOX_FAILURE_BOX_HPP
#define FAILURE_BOX_FAILURE_BOX_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <random> // std::[random_device
                  //      |default_random_engine
                  //      |uniform_int_distribution]

#ifdef BUILD_TESTING
#   include <gtest/gtest.h>                       // FRIEND_TEST
#else
#   define FRIEND_TEST(TEST_CASE_NAME, TEST_NAME) // disable
#endif // ifdef BUILD_TESTING



class FailureBox : private std::uniform_int_distribution<unsigned int>
{
public:
    // never fail by default
    FailureBox(const unsigned int expected_queries_per_failure = 0);

    bool
    query();

private:
    FRIEND_TEST(constructor, a);
    FRIEND_TEST(constructor, b);

    typedef std::default_random_engine                  RandomEngine;
    typedef std::uniform_int_distribution<unsigned int> Distribution;

    static thread_local RandomEngine engine;
}; // class FailureBox

#endif // FAILURE_BOX_FAILURE_BOX_HPP
