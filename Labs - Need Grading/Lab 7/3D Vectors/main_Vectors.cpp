#include <vector>
#include <iomanip> // For std::setw and std::setprecision
#include "multiDimension_Vector.h"
#include "distance.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream> // For std::istringstream

using namespace std;

int main() {
    vector<double_vector> my_double_vector;
    vector<my_distance> all_pairs_distances;

    ifstream in_file("vectors.txt"); // Assume this file has vectors of arbitrary dimensions
    if (!in_file.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1; // Exit with error code
    }

    string line;
    int id = 0;

    // Read vectors from the file
    while (getline(in_file, line)) {
        istringstream iss(line);
        vector<double> components;
        double value;

        while (iss >> value) {
            components.push_back(value);
        }

        if (components.size() >= 2) { // Ensure vector dimension is at least 2
            my_double_vector.emplace_back(components, id++);
        }
    }

    // Compute pairwise distances and sort them
    //avoid duplicate - using j = i + 1
    for (size_t i = 0; i < my_double_vector.size(); ++i) {
        for (size_t j = 0; j < my_double_vector.size(); ++j) {
            if (i != j) { // Compute distance only for different pairs
                double dist = cosine_distance(my_double_vector[i], my_double_vector[j]);
                all_pairs_distances.emplace_back(i, j, dist);
            }
        }
    }

    sort(all_pairs_distances.begin(), all_pairs_distances.end(), [](const my_distance &a, const my_distance &b) {
        // Sort based on the cosine distance first, and then by pair ids for equal distances.
        if (a.cos_distance == b.cos_distance)
            return a.id_1 == b.id_1 ? a.id_2 < b.id_2 : a.id_1 < b.id_1;
        return a.cos_distance < b.cos_distance;
    });

    // Print out the vector pairs and their cosine distances
    cout << "Vector Pairs (Ordered by Cosine Closeness):" << endl;
    for (const auto& pair : all_pairs_distances) {
        cout << "(" << pair.id_1 << ", " << pair.id_2 << "): ";
        cout << fixed << setprecision(4) << pair.cos_distance << endl;
    }

    in_file.close();
    return 0;
}
