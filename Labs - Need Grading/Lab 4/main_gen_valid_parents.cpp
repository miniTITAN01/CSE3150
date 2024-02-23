#include <iostream>
#include <vector>
#include "wellFormedSymbols_Generator.h"
#include "gen_permutation.h"

using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n ;
    cout << endl;

    for (int trial = 0; trial < 10; ++trial) {
        cout << "Trial " << (trial + 1) << ":" << endl;

        vector<int> symbols(2 * n + 1);
        // Step 1: Initialize the list
        for (int i = 0; i < n; ++i) symbols[i] = 1;
        for (int i = n; i < 2 * n + 1; ++i) symbols[i] = -1;
        // Print the original list
        cout << "Original list: ";
        for (int symbol : symbols) {
            cout << symbol << " ";
        }
        cout << endl;


        // Step 2: Scramble the list using Fisher-Yates
        compute_permutation_of_array(&symbols[0], symbols.size());

        // Print the scrambled list
        cout << "Scrambled list: ";
        for (int symbol : symbols) {
            cout << symbol << " ";
        }
        cout << endl;

        // Check if the first element is -1 and skip processing if so
        if (symbols[0] == -1) {
            cout << "Sequence starts with -1, skipping this sequence." << endl;
            cout << endl;
            continue; // Skip this trial

        }

        // Steps 3 to 7: Process the scrambled list into a well-formed sequence
        vector<int> wellFormedSymbols = generateWellFormedSymbols(symbols);

        // Print the well-formed symbols sequence
        cout << "Well-formed symbols sequence: ";
        for (int symbol : wellFormedSymbols) {
            cout << symbol << " ";
        }
        cout << endl;
        cout << endl;
    }

    return 0;
}
