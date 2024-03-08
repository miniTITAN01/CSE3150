#ifndef READ_FILE_H
#define READ_FILE_H

#include <vector>
#include <string>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Representation of infinity
using Matrix = vector<vector<int>>; //defining a 2D vector used as a matrix

// Function to initialize the adjacency matrices for the barbell graph
void InitBarbellAdjacencyMatrices(Matrix& D1, Matrix& D0, Matrix& Dminus1, int n);

// Function to print a matrix
void PrintMatrix(const Matrix& matrix);

#endif // READ_FILE_H
