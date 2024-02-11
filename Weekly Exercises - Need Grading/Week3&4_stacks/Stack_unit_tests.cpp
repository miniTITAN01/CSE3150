#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "StackQueueFunctions.h"

TEST_CASE("Testing stack and queue functionality") {
    // Assuming "input.txt" exists and has appropriate content for testing
    SUBCASE("Test stack with positive sum") {
        auto s = fillStackFromTextFile("positive_input.txt"); // Ensure this file exists and sums to a positive number
        CHECK_NOTHROW(checkAndPopStack(s));
    }

    SUBCASE("Test queue with positive sum") {
        auto q = fillQueueFromTextFile("positive_input.txt"); // Ensure this file exists and sums to a positive number
        CHECK_NOTHROW(checkAndDequeueQueue(q));
    }

    SUBCASE("Test stack with negative sum") {
        auto s = fillStackFromTextFile("negative_input.txt"); // Ensure this file exists and sums to a negative number
        CHECK_THROWS_AS(checkAndPopStack(s), StackQueueException);
    }

    SUBCASE("Test queue with negative sum") {
        auto q = fillQueueFromTextFile("negative_input.txt"); // Ensure this file exists and sums to a negative number
        CHECK_THROWS_AS(checkAndDequeueQueue(q), StackQueueException);
    }
}

TEST_CASE("Testing stack and queue functionality with various inputs") {

    SUBCASE("Test stack with empty input") {
        auto s = fillStackFromTextFile("empty_input.txt");
        CHECK_NOTHROW(checkAndPopStack(s));
    }

    SUBCASE("Test queue with empty input") {
        auto q = fillQueueFromTextFile("empty_input.txt");
        CHECK_NOTHROW(checkAndDequeueQueue(q));
    }

    SUBCASE("Test stack with a single positive number") {
        auto s = fillStackFromTextFile("single_positive.txt");
        CHECK_NOTHROW(checkAndPopStack(s));
    }

    SUBCASE("Test queue with a single positive number") {
        auto q = fillQueueFromTextFile("single_positive.txt");
        CHECK_NOTHROW(checkAndDequeueQueue(q));
    }

    SUBCASE("Test stack with a single negative number") {
        auto s = fillStackFromTextFile("single_negative.txt");
        CHECK_THROWS_AS(checkAndPopStack(s), StackQueueException);
    }

    SUBCASE("Test queue with a single negative number") {
        auto q = fillQueueFromTextFile("single_negative.txt");
        CHECK_THROWS_AS(checkAndDequeueQueue(q), StackQueueException);
    }

    SUBCASE("Test stack with large numbers leading to negative sum") {
    auto s = fillStackFromTextFile("large_numbers.txt");
    CHECK_THROWS_AS(checkAndPopStack(s), StackQueueException);
    }

    SUBCASE("Test queue with large numbers leading to negative sum") {
        auto q = fillQueueFromTextFile("large_numbers.txt");
        CHECK_THROWS_AS(checkAndDequeueQueue(q), StackQueueException);
    }


    SUBCASE("Test stack with oscillating sum") {
        auto s = fillStackFromTextFile("oscillating_sum.txt");
        CHECK_NOTHROW(checkAndPopStack(s));
    }

    SUBCASE("Test queue with oscillating sum") {
        auto q = fillQueueFromTextFile("oscillating_sum.txt");
        CHECK_NOTHROW(checkAndDequeueQueue(q));
    }
}

