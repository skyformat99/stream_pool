#include <chrono>                      // std::chrono::system_clock::now
#include <failure_box/failure_box.hpp> // FailureBox

#if !HAVE_CPP_THREAD_LOCAL
#   include <atomic> // std::atomic_flag
#endif // if !HAVE_CPP_THREAD_LOCAL

namespace {

#if !HAVE_CPP_THREAD_LOCAL
std::atomic_flag engine_lock = ATOMIC_FLAG_INIT;
#else
thread_local
#endif /// if !HAVE_CPP_THREAD_LOCAL
FailureBox::RandomEngine engine(
    static_cast<FailureBox::RandomEngine::result_type>(
        std::chrono::system_clock::now().time_since_epoch()
                                        .count()
    )
);

} // namespace {


FailureBox::FailureBox(const unsigned int expected_queries_per_failure)
    : Distribution(expected_queries_per_failure == 0, // 1 if never fail
                   expected_queries_per_failure - 1)  // UINT_MAX if never fail
{}


bool
FailureBox::query()
{
#if !HAVE_CPP_THREAD_LOCAL
    while (engine_lock.test_and_set(std::memory_order_acquire))
        ; // busy block
#endif // if !HAVE_CPP_THREAD_LOCAL

    const bool outcome = (*this)(engine) != 0;

#if !HAVE_CPP_THREAD_LOCAL
    engine_lock.clear(std::memory_order_release);
#endif // if !HAVE_CPP_THREAD_LOCAL

    return outcome;
}
