
#include "doctest.h"
#include "gen_permutation.h"
#include "wellFormedSymbols_Generator.h"

// Helper function to check if a sequence is well-formed
bool isWellFormed(const std::vector<int>& sequence) {
    int balance = 0;
    for (int symbol : sequence) {
        balance += symbol;
        if (balance < 0) {
            return false; // An imbalance occurred; not well-formed
        }
    }
    return balance == 0; // A well-formed sequence ends with a balance of 0
}

TEST_CASE("Testing generateWellFormedSymbols") {
    SUBCASE("Handles empty input") {
        std::vector<int> emptyInput;
        auto result = generateWellFormedSymbols(emptyInput);
        CHECK(result.empty() == true);
    }

    SUBCASE("Skips sequence starting with -1") {
        std::vector<int> startsWithNegativeOne = {-1, 1, -1, 1, -1};
        auto result = generateWellFormedSymbols(startsWithNegativeOne);
        CHECK(result.empty() == true);
    }

    SUBCASE("Rearranges list correctly") {
        std::vector<int> input = {1,-1,-1,1,1,-1,1,-1,-1}; // Input with a known rearrangement
        auto result = generateWellFormedSymbols(input);
        // Expected result after rearrangement
        std::vector<int> expected = {1,1,-1,1,-1,-1,1,-1}; // Adjust based on your function's logic

        CHECK(result == expected);
    }

    SUBCASE("Forms a well-balanced list from complex input") {
        std::vector<int> complexInput = {1, 1, 1, -1, -1, 1, -1, -1, -1}; // Complex input
        auto result = generateWellFormedSymbols(complexInput);
        // Verify the result is well-formed
        int balance = 0;
        bool isWellFormed = true;
        for (int symbol : result) {
            balance += symbol;
            if (balance < 0) {
                isWellFormed = false;
                break; // An imbalance occurred
            }
        }
        CHECK(isWellFormed == true);
        CHECK(balance == 0); // The sequence should end balanced
    }

}
