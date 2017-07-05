#include "gtest/gtest.h"               // TEST, ASSERT_*, EXPECT_*
#include "failure_box/failure_box.hpp" // FailureBox



TEST(constructor, a)
{
    ASSERT_EQ(1, FailureBox().a());
    ASSERT_EQ(1, FailureBox(0).a());
    ASSERT_EQ(0, FailureBox(1).a());
    ASSERT_EQ(0, FailureBox(100).a());
    ASSERT_EQ(0, FailureBox(1000).a());
}


TEST(constructor, b)
{
    ASSERT_LE(1,   FailureBox().b());
    ASSERT_LE(1,   FailureBox(0).b());
    ASSERT_EQ(0,   FailureBox(1).b());
    ASSERT_EQ(99,  FailureBox(100).b());
    ASSERT_EQ(999, FailureBox(1000).b());
}


TEST(query, default)
{
    FailureBox box;

    // default never fails
    for (unsigned int i = 0; i < 10000; ++i)
        ASSERT_TRUE(box.query());
}


TEST(query, random)
{
    for (unsigned int qpf = 1000; qpf > 0; qpf /= 10) {
        FailureBox box(qpf);

        unsigned int min_expected  = qpf / 50;
        unsigned int max_expected  = qpf * 50;
        unsigned int count_queries = 0;

        while (++count_queries, box.query())
            EXPECT_GE(max_expected, count_queries);


        EXPECT_LE(min_expected, count_queries);
    }
}
