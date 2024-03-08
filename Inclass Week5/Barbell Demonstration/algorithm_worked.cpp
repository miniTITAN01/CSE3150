// algorithm.cpp
#include "algorithm.h"  // Include the file that reads matrices

void ExpensiveDigraphExactPaths_improved(Matrix& D1, Matrix& D0, Matrix& Dminus1) {
    int n = D0.size();  // Assuming square matrices

    // Copy the original matrices to use for reference during updates
    Matrix D1_next = D1;
    Matrix D0_next = D0;
    Matrix Dminus1_next = Dminus1;

    for (int l = 2; l <= 3 * n * n + 1; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    // Skip if there's no path from i to k or k to j
                    if (D1[i][k] == INF || Dminus1[k][j] == INF) continue;

                    // Check if there's a path from i to j through k with net 0 weight
                    if (D1[i][k] + Dminus1[k][j] == 0)
                        D0_next[i][j] = 0;

                    // Skip if there's no path from i to k or k to j
                    if (Dminus1[i][k] == INF || D1[k][j] == INF) continue;

                    // Check if there's a path from i to j through k with net 0 weight
                    if (Dminus1[i][k] + D1[k][j] == 0)
                        D0_next[i][j] = 0;
                }
            }
        }

        // Update the matrices for the next iteration
        D1 = D1_next;
        D0 = D0_next;
        Dminus1 = Dminus1_next;
    }
}






