#ifndef FAILURE_BOX_FAILURE_BOX_HPP
#define FAILURE_BOX_FAILURE_BOX_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <random> // std::[random_device
                  //      |default_random_engine
                  //      |uniform_int_distribution]



class FailureBox : private std::uniform_int_distribution<unsigned int>
{
public:
    FailureBox(const unsigned int expected_queries_per_failure);

    bool
    query();

private:
    typedef std::default_random_engine                  RandomEngine;
    typedef std::uniform_int_distribution<unsigned int> Distribution;

    static thread_local RandomEngine  engine;
}; // class FailureBox

#endif // FAILURE_BOX_FAILURE_BOX_HPP
