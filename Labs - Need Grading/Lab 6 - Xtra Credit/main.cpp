#include "read_file.h"
#include "algorithm.h"
#include <ostream>
#include <iostream>

using namespace std;
int main() {
    Matrix D1, D0, Dminus1;
    InitAdjacencyMatrices(D1, D0, Dminus1);  // Initialize matrices
    
    ExpensiveDigraphExactPaths(D1, D0, Dminus1);  // Compute the algorithm

    // Print the matrices after computation
    cout << "Matrix D1:" << endl;
    PrintMatrix(D1);
    
    cout << "Matrix D0:" << endl;
    PrintMatrix(D0);

    cout << "Matrix Dminus1:" << endl;
    PrintMatrix(Dminus1);
    
    return 0;
}
