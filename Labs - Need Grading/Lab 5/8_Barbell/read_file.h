#ifndef READ_FILE_H
#define READ_FILE_H

#include <vector>
#include <string>
#include <istream>

extern const int INF;
using Matrix = std::vector<std::vector<int>>;

Matrix ReadMatrixFromFile(const std::string& filename);
Matrix ReadMatrixFromStream(std::istream& in);

void InitAdjacencyMatrices(Matrix& D1, Matrix& D0, Matrix& Dminus1);
void PrintMatrix(const Matrix& matrix);

#endif // READ_FILE_H
