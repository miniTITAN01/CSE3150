#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <sstream>
#include <fstream>
#include "ints_readVectors.h"
#include "ints_Vector.h"



// Test the default constructor
TEST_CASE("int_vector default constructor") {
    int_vector vec;
    CHECK(vec.id == -1);
    CHECK(vec.from == 0);
    CHECK(vec.to == 0);
}

// Test the parameterized constructor
TEST_CASE("int_vector parameterized constructor") {
    int_vector vec(1, 2, 3);
    CHECK(vec.id == 1);
    CHECK(vec.from == 2);
    CHECK(vec.to == 3);
}

// Test the copy constructor
TEST_CASE("int_vector copy constructor") {
    int_vector original(1, 2, 3);
    int_vector copy = original;
    CHECK(copy.id == original.id);
    CHECK(copy.from == original.from);
    CHECK(copy.to == original.to);
}

// Test reading integers into a vector
TEST_CASE("ints_read_vector functionality") {
    // Test with a simple input
    SUBCASE("Simple input") {
        std::istringstream iss("10 20 30");
        auto result = ints_read_vector(iss);
        CHECK(result.size() == 3);
        CHECK(result[0] == 10);
        CHECK(result[1] == 20);
        CHECK(result[2] == 30);
    }

    // Test with negative numbers
    SUBCASE("Negative numbers") {
        std::istringstream iss("-1 -2 -3");
        auto result = ints_read_vector(iss);
        CHECK(result.size() == 3);
        CHECK(result[0] == -1);
        CHECK(result[1] == -2);
        CHECK(result[2] == -3);
    }

    // Test with mixed numbers and non-integer input (which should be ignored or cause an early stop)
    SUBCASE("Mixed input with non-integer") {
        std::istringstream iss("1 2 three 4");
        auto result = ints_read_vector(iss);
        CHECK(result.size() == 2); // Assuming the reading stops at non-integer "three"
        CHECK(result[0] == 1);
        CHECK(result[1] == 2);
    }

    // Test with an empty input
    SUBCASE("Empty input") {
        std::istringstream iss("");
        auto result = ints_read_vector(iss);
        CHECK(result.empty() == true);
    }
}

// Test reading a single line of integers into a vector
TEST_CASE("ints_read_one_line functionality") {
    // Test with a single line of input
    SUBCASE("Single line input") {
        std::istringstream iss("1 2 3");
        auto result = ints_read_one_line(iss);
        CHECK(result.size() == 3);
        CHECK(result[0] == 1);
        CHECK(result[1] == 2);
        CHECK(result[2] == 3);
    }

    // Test with multiple lines (should only read the first line)
    SUBCASE("Multiple lines input") {
        std::istringstream iss("1 2 3\n4 5 6");
        auto result = ints_read_one_line(iss);
        CHECK(result.size() == 3); // Only the first line should be read
        CHECK(result[0] == 1);
        CHECK(result[1] == 2);
        CHECK(result[2] == 3);
    }

    // Test with an empty line
    SUBCASE("Empty line") {
        std::istringstream iss("\n1 2 3");
        auto result = ints_read_one_line(iss);
        CHECK(result.empty() == true); // The first line is empty, so no integers should be read
    }
}

TEST_CASE("Parsing input with special delimiters") {
    std::string input = "1,2;3 4,5;6";
    auto result = parse_input_with_delimiters(input);
    CHECK(result.size() == 6);
    CHECK(result[0] == 1);
    CHECK(result[1] == 2);
    CHECK(result[2] == 3);
    CHECK(result[3] == 4);
    CHECK(result[4] == 5);
    CHECK(result[5] == 6);
}


TEST_CASE("Handling large numbers") {
    std::string input = "9223372036854775807, -9223372036854775808";
    auto result = parse_input_with_delimiters(input);
    CHECK(result.size() == 2);
    CHECK(result[0] == 9223372036854775807LL);
    CHECK(result[1] == -9223372036854775807LL - 1); // Since -9223372036854775808 is out of range for literals
}


TEST_CASE("Special error handling") {
    // Test the function's ability to recover from errors or unexpected input
    SUBCASE("Non-numeric input after numeric") {
        std::istringstream iss("1 2 three");
        auto result = ints_read_vector(iss);
        CHECK(result.size() == 2); // Assuming function stops at first non-numeric
        CHECK(result[0] == 1);
        CHECK(result[1] == 2);
    }

}
