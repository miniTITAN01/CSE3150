#include <iostream>
#include <vector>
#include "prefix_sum.h"
#include "gen_permutation.h"

using namespace std;

vector<int> generateWellFormedSymbols(const std::vector<int>& scrambledSymbols) {
    // Check if the first element is -1 and return an empty vector if so
    if (scrambledSymbols.empty() || scrambledSymbols[0] == -1) {
        return vector<int>(); // Return an empty vector to indicate skipping
    }

    // Step 3: Find the lowest depth of any valley
    int lowestValleyIndex = index_of_lowest_prefix_sum_element(&scrambledSymbols[0], scrambledSymbols.size());

    // Steps 4, 5, 6, and 7: Rearrange the list
    vector<int> P1(scrambledSymbols.begin(), scrambledSymbols.begin() + lowestValleyIndex + 1);
    vector<int> P2(scrambledSymbols.begin() + lowestValleyIndex + 1, scrambledSymbols.end());

    // Step 6: Drop the last -1 from P1 to create P1'
    P1.pop_back(); // Removes the last element, assuming it's -1

    // Step 7: Combine P2 and P1' to form a well-balanced list
    vector<int> wellBalancedSymbols;
    wellBalancedSymbols.insert(wellBalancedSymbols.end(), P2.begin(), P2.end());
    wellBalancedSymbols.insert(wellBalancedSymbols.end(), P1.begin(), P1.end());

    return wellBalancedSymbols;
}
