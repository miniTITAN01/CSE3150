#include <iostream>
#include <vector>
#include <limits>

// Define INF as a constant for infinity.
const int INF = std::numeric_limits<int>::max();

std::ostream &operator<<(std::ostream &os, const std::vector<int> &my_vector)
{
    for (size_t i = 0; i < my_vector.size(); ++i) {
        if (my_vector[i] == INF) {
            os << "2 "; // Print '2' for infinity.
        } else {
            os << my_vector[i] << " ";
        }
    }
    os << "\n"; // End the line after printing the vector.
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<int>> &my_matrix)
{
    for (const auto &row_vector : my_matrix) {
        os << row_vector; // The operator<< for std::vector<int> will be called here.
    }
    return os;
}
