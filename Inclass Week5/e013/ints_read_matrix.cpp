#include <istream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;
const int INF = std::numeric_limits<int>::max(); // Representation of infinity

vector<int> ints_read(istringstream &is_line, int g) {
    vector<int> row;
    int number;
    while (is_line >> number) {
        if (number == 2) {
            // According to the provided screenshot, a '2' represents infinity
            row.push_back(INF);
        } else if (number == g) {
            // If the number is equal to g, it represents an edge with the corresponding weight
            row.push_back(g);
        } else {
            // Any other number is considered as not having an edge, thus infinity
            row.push_back(INF);
        }
    }
    return row;
}

vector<vector<int>> ints_read_matrix(istream &in_stream, int g) {
    vector<vector<int>> matrix;
    string line;

    while (getline(in_stream, line)) {
        istringstream is_line(line);
        matrix.push_back(ints_read(is_line, g));
    }

    return matrix;
}
