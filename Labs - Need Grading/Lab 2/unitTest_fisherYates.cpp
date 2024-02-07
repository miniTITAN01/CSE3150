#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "fisher_yates.h"

// Helper function to compare arrays for equality in content regardless of order
bool sameElements(const int* a, int aLen, const int* b, int bLen) {
    if (aLen != bLen) return false;
    std::vector<int> aVec(a, a + aLen);
    std::vector<int> bVec(b, b + bLen);
    std::sort(aVec.begin(), aVec.end());
    std::sort(bVec.begin(), bVec.end());
    return aVec == bVec;
}

TEST_CASE("Fisher-Yates Shuffle") {
    int array[5] = {1, 2, 3, 4, 5};
    int originalArray[5] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int originalArraySize = sizeof(originalArray) / sizeof(originalArray[0]);

    fisherYatesShuffle(array, size);

    SUBCASE("Length Preservation") {
        CHECK(size == sizeof(array) / sizeof(array[0]));
    }

    SUBCASE("Invariance of Elements") {
        CHECK(sameElements(array, size, originalArray, originalArraySize ));
    }
}

TEST_CASE ("Swap Function"){
    SUBCASE("swap tests"){
        int first = 5, second = 10;
        int save_first = first, save_second = second;
        swap (&first, &second);

        CHECK(first == save_second);
        CHECK(second == save_first);
    }
}
TEST_CASE("Well-Balaced and Imbalance Checks"){
    SUBCASE("is_well_balanced tests"){
        int balancedArray[] = {1, -1, 1, -1};
        int unBalancedArray1[] = {1, 1, -1, -1, -1};
        int unBalancedArray2[] = {1, 1, -1, -1, 1};
        int unBalancedArray3[] = {-1,1,-1,1} ;

        CHECK(is_well_balanced(balancedArray, 4) == true);
    
        CHECK(is_well_balanced(unBalancedArray1, 5) == false);
        CHECK(is_well_balanced(unBalancedArray2, 5) == false);
        CHECK(is_well_balanced(unBalancedArray3, 4) == false);
    }

    SUBCASE("hasMoreClosingThanOpenings tests"){
        int testArray1[] = {-1,1,-1,1}; //Start with more closings
        int testArray2[] = {1, -1, 1, -1}; //never has more closing than opening
        int testArray3[] = {1, 1, -1, -1, -1};

        CHECK(hasMoreClosingsThanOpenings(testArray1, 4) == true);
        CHECK(hasMoreClosingsThanOpenings(testArray2, 4) == false);
        CHECK(hasMoreClosingsThanOpenings(testArray3, 5) == true);


    }

    SUBCASE("hasMoreOpeningThanClosing tests"){
        int testArray1 [] = {1, 1, -1, 1}; // Ends with more openings
        int testArray2 [] = {1, -1, 1, -1}; //balanced
        int testArray3[] = {1, 1, -1, -1, 1};

        CHECK(hasMoreOpeningsThanClosings(testArray1, 4) == true);
        CHECK(hasMoreOpeningsThanClosings(testArray2, 4) == false);
        CHECK(hasMoreOpeningsThanClosings(testArray3, 5) == true);
    }
}