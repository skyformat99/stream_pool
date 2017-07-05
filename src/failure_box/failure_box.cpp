#include <chrono>                      // std::chrono::system_clock::now
#include <failure_box/failure_box.hpp> // FailureBox



thread_local FailureBox::RandomEngine FailureBox::engine(
    static_cast<FailureBox::RandomEngine::result_type>(
        std::chrono::system_clock::now().time_since_epoch()
                                        .count()
    )
);


FailureBox::FailureBox(const unsigned int expected_queries_per_failure)
    : Distribution(expected_queries_per_failure == 0, // 1 if never fail
                   expected_queries_per_failure - 1)  // UINT_MAX if never fail
{}


bool
FailureBox::query()
{
    return (*this)(engine) != 0;
}
