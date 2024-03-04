#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "lambdas_Operations.h" // Update this include path as necessary
using namespace std;

TEST_SUITE("PerfectNumbers") {
    TEST_CASE("Identifying perfect numbers") {
        CHECK(is_perfect_number(6) == true); // Corrected function name
        CHECK(is_perfect_number(28) == true);
        CHECK(is_perfect_number(496) == true);
        CHECK(is_perfect_number(8128) == true);
    }

    TEST_CASE("Identifying non-perfect numbers") {
        CHECK(is_perfect_number(10) == false);
        CHECK(is_perfect_number(12) == false);
        CHECK(is_perfect_number(27) == false);
        CHECK(is_perfect_number(100) == false);
    }

    TEST_CASE("Edge cases for perfect number check") {
        CHECK(is_perfect_number(0) == false); // Considering 0 as not a perfect number
        CHECK(is_perfect_number(-6) == false); // Negative numbers are not considered
        CHECK(is_perfect_number(1) == false); // 1 is not a perfect number as it has no proper divisors other than itself
    }
}

TEST_SUITE("ModifyingReferenceValues") {
    TEST_CASE("Effect of divides_by_then_set_d_1 on variable d") {
        int d = 0;
        vector<int> vect = {1}; // Minimal vector to demonstrate effect
        divides_by_then_set_d_1(vect, d);
        CHECK(d == 1);
    }
}