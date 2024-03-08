#include <iostream>
#include <istream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

#include "ints_read_matrix.h"
#include "ints_write.h"
#include "expensive_digraph_exact_paths.h"

int main() {

    using namespace std;

    // Correctly declare 'files' as a vector of strings
    vector<string> files = {"example_0.txt", "example_1.txt", "example_m1.txt"};

    // Correctly open files using .c_str() for conversion to const char*
    ifstream in_file_0(files[0].c_str());
    if (!in_file_0.is_open()) {
        cerr << "Could not open file: " << files[0] << endl;
        return 1;
    }

    ifstream in_file_1(files[1].c_str());
    if (!in_file_1.is_open()) {
        cerr << "Could not open file: " << files[1] << endl;
        return 1;
    }

    ifstream in_file_m1(files[2].c_str());
    if (!in_file_m1.is_open()) {
        cerr << "Could not open file: " << files[2] << endl;
        return 1;
    }

    vector<vector<int>> zero_matrix, plus_one_matrix, minus_one_matrix;

    zero_matrix = ints_read_matrix(in_file_0, 0);
    for (auto my_vector: zero_matrix){
        cout << my_vector << endl;
    }
    cout <<"----------------------" <<endl;

    plus_one_matrix = ints_read_matrix(in_file_1, 1);
    for (auto my_vector: plus_one_matrix){
        cout << my_vector << endl;
    }
    cout <<"----------------------" <<endl;

    minus_one_matrix = ints_read_matrix(in_file_m1, -1);
    for (auto my_vector: minus_one_matrix){
        cout << my_vector << endl;
    }
    cout <<"----------------------" <<endl;

    // After reading the matrices:
    computeExpensiveDigraphExactPaths(minus_one_matrix, zero_matrix, plus_one_matrix);

    // You can then print the matrices to verify the result:
    cout << "D(-1) Matrix after computation:" << endl;
    cout << minus_one_matrix << "----------------------" << endl;

    cout << "D(0) Matrix after computation:" << endl;
    cout << zero_matrix << "----------------------" << endl;

    cout << "D(1) Matrix after computation:" << endl;
    cout << plus_one_matrix << "----------------------" << endl;


    // Make sure to close your files before ending the program
    in_file_0.close();
    in_file_1.close();
    in_file_m1.close();

    return 0;
}