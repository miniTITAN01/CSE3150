#include "read_file.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> // Required for std::istringstream
#include <limits>  // Required for std::numeric_limits

using namespace std; 


void InitBarbellAdjacencyMatrices(Matrix& D1, Matrix& D0, Matrix& Dminus1, int m) {
    int n = 2 * m + 1; // Total nodes in the graph is 2m + 1

    // Resize matrices to accommodate n nodes
    D1.assign(n, std::vector<int>(n, INF));
    D0.assign(n, std::vector<int>(n, INF));
    Dminus1.assign(n, std::vector<int>(n, INF));

    // Populate D1 with +1 weights for the clockwise edges in the first cluster
    for (int i = 0; i < m - 1; ++i) {
        D1[i][i + 1] = 1;
    }
    // Populate D1 with the +1 bridge edge from the last node of the first cluster to the first node of the second cluster
    D1[m - 1][m] = 1;

    // Populate Dminus1 with -1 weights for the clockwise edges in the second cluster
    for (int i = m; i < 2 * m; ++i) {
        Dminus1[i][(i + 1) % (m + 1) + m] = -1;
    }
    
    // There are no bridges that lead from the second cluster back to the first cluster
    // The -1 edge from node 2m to node m is removed

    // Set self-loops to 0 cost in D0
    for (int i = 0; i < n; ++i) {
        D0[i][i] = 0;
    }
}


// Print a matrix
void PrintMatrix(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            if (elem == INF) {
                cout << "INF\t";
            } else {
                cout << elem << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}
