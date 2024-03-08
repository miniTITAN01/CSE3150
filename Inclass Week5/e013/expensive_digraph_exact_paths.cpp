#include "expensive_digraph_exact_paths.h"
#include <algorithm>

const int INF = std::numeric_limits<int>::max();

void computeExpensiveDigraphExactPaths(
    std::vector<std::vector<int>>& D_minus_1,
    std::vector<std::vector<int>>& D_0,
    std::vector<std::vector<int>>& D_1
) {
    int n = D_0.size();
    for (int l = 2; l <= 3 * n * n + 1; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    // Check if a path exists between i and k in D(-1) and between k and j in D(1)
                    if (D_minus_1[i][k] < INF && D_1[k][j] < INF && (D_minus_1[i][k] + D_1[k][j] == 0)) {
                        D_0[i][j] = 0;
                    }
                    // Check if a path exists between i and k in D(1) and between k and j in D(0)
                    if (D_1[i][k] < INF && D_0[k][j] < INF && (D_1[i][k] + D_0[k][j] == 1)) {
                        D_1[i][j] = 1;
                    }
                    // Check if a path exists between i and k in D(-1) and between k and j in D(0)
                    if (D_minus_1[i][k] < INF && D_0[k][j] < INF && (D_minus_1[i][k] + D_0[k][j] == -1)) {
                        D_minus_1[i][j] = -1;
                    }
                }
            }
        }
    }
}

