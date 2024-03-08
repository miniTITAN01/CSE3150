#include "read_file.h"
#include "algorithm.h"  // Assume this header declares the ExpensiveDigraphExactPaths function
#include <iostream>

using namespace std;

int main() {

    int m;
    cout << "Enter the size of the smaller cluster of the barbell graph: ";
    cin >> m; // User inputs the size of the smaller cluster

    if (m < 1) {
        cerr << "The size of the cluster must be at least 1." << endl;
        return 1;
    }

    int n = 2 * m + 1; // Total number of nodes in the barbell graph

    // Initialize the adjacency matrices
    Matrix D1(n, vector<int>(n, INF));
    Matrix D0(n, vector<int>(n, INF));
    Matrix Dminus1(n, vector<int>(n, INF));

    // Use the function to initialize the matrices for the barbell graph
    InitBarbellAdjacencyMatrices(D1, D0, Dminus1, m);
    // Print the matrices 
    cout << "Matrix D1:" << endl;
    PrintMatrix(D1);
    
    cout << "Matrix D0:" << endl;
    PrintMatrix(D0);

    cout << "Matrix Dminus1:" << endl;
    PrintMatrix(Dminus1);

    // Run the algorithm
    ExpensiveDigraphExactPaths_improved(D1, D0, Dminus1);

    // Print the matrices after computation
    cout << "Matrix D1 after computation:" << endl;
    PrintMatrix(D1);

    cout << "Matrix D0 after computation:" << endl;
    PrintMatrix(D0);

    cout << "Matrix Dminus1 after computation:" << endl;
    PrintMatrix(Dminus1);

    return 0;
}
