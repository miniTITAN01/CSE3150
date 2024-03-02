#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "ints_Vector.h" // 

using namespace std;

int main() {

    ifstream in_file("vectors_2D.txt"); // Directly open the file with the constructor

    if (!in_file.is_open()) { // Check if the file is open
        cerr << "Unable to open file" << endl;
        return 1; // Return a non-zero value to indicate failure
    }

    vector<int_vector> vect;

    int id = 0; // Initialize id to 0
    int from, to;
    cout << "Original Input:" << endl;
    while (in_file >> from >> to) { // Read integers directly
        cout << from << " " << to << endl;
        int_vector i_v;
        i_v.from = from;
        i_v.to = to;
        i_v.id = id++;
        vect.push_back(i_v);
    }
    in_file.close(); // Close the file once done with reading

    cout << "------------------" << endl;
    cout << "Converting to Vectors" << endl;
    for (auto v : vect) {
        cout << v.id << ": "  << v.from << " to " << v.to << endl;
    }

    // Sort the vector in reverse order based on id
    sort(vect.begin(), vect.end(), [](const int_vector &left, const int_vector &right) {
        return left.id > right.id; // This will sort in descending order of id
    });

    cout << "------------------" << endl;
    cout << "Vectors in reverse order:" << endl;
    // Output the sorted vectors
    for (const auto &v : vect) {
        cout << "ID " << v.id << " -> (" << v.from << ", " << v.to << ")" << endl;
    }

    return 0;
}
