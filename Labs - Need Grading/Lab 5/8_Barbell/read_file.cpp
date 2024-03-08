#include "read_file.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> // Required for std::istringstream
#include <limits>  // Required for std::numeric_limits
#include <stdexcept>

using namespace std;

const int INF = numeric_limits<int>::max(); // Representation of infinity

// Type alias for a matrix of integers
using Matrix = vector<std::vector<int>>;

Matrix ReadMatrixFromStream(std::istream& in) {
    Matrix matrix;
    std::string line;

    // Read each line and infer the matrix dimensions from the content
    while (getline(in, line)) {
        std::istringstream lineStream(line);
        std::vector<int> row;
        int value;

        while (lineStream >> value) {
            // Use the maximum integer value to represent 'infinity' for 2
            row.push_back(value == 2 ? INF : value);
        }

        // Ensure all rows have the same number of columns
        if (!matrix.empty() && row.size() != matrix[0].size()) {
            throw std::runtime_error("Matrix row size mismatch");
        }

        matrix.push_back(row);
    }

    // Ensure the file was not empty
    if (matrix.empty()) {
        throw std::runtime_error("Empty matrix input");
    }

    return matrix;
}

// This function now simply opens the file and delegates to ReadMatrixFromStream
Matrix ReadMatrixFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    // Delegate to the general matrix reading function
    return ReadMatrixFromStream(file);
}





// Function to initialize D1, D0, and Dminus1 from file
void InitAdjacencyMatrices(Matrix& D1, Matrix& D0, Matrix& Dminus1) {
    D1 = ReadMatrixFromFile("D1.txt");
    D0 = ReadMatrixFromFile("D0.txt");
    Dminus1 = ReadMatrixFromFile("Dminus1.txt");
}

// Function to print the matrix
void PrintMatrix(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            if (elem == std::numeric_limits<int>::max()) {
                cout << "INF" << "\t";
            } else {
                cout << elem << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}
