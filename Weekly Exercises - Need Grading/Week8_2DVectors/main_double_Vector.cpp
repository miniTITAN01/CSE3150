#include <vector>
#include <iomanip> // For std::setw and std::setprecision
#include "double_Vector.h"
#include "distance.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    vector<double_vector> my_double_vector;
    vector<my_distance> all_pairs_distances;

    ifstream in_file;
    in_file.open("vectors_2D.txt");

    int id = 0;
    double from, to;

    while (in_file >> from >> to) {
        double_vector d_vector = double_vector(from, to, id++);
        my_double_vector.push_back(d_vector);
    }

    cout << "Vector Components and Cosine Distance with Itself:" << endl;
    cout << left << setw(10) << "Vector" << setw(15) << "Components" << setw(30) << "Cosine Distance with Itself" << endl;

    for (auto& vect : my_double_vector) {
        cout << setw(10) << id++ << "(" << setw(6) << vect.x << ", " << setw(6) << vect.y << ")" << setw(15) << " " << setw(15) << setprecision(4) << cosine_distance(vect, vect) << endl;
    }
    cout << endl;

    int size = my_double_vector.size();

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) { // Start from i + 1 to avoid redundant pairs and self-comparison
            my_distance my_distance1(i, j, cosine_distance(my_double_vector[i], my_double_vector[j]));
            all_pairs_distances.push_back(my_distance1);
        }
    }

   // Sort distances based on cosine closeness
    sort(all_pairs_distances.begin(), all_pairs_distances.end(),
         [](const my_distance &left, const my_distance &right) -> bool {
             return left.cos_distance < right.cos_distance;
         });

    // Outputting vector pairs with their components and cosine closeness
    cout << "Vector Pairs (Ordered by Cosine Closeness):" << endl;
    cout << left << setw(20) << "Vector Pair IDs" << setw(30) << "Vector Components" << setw(20) << "Cosine Closeness" << endl;

    for (const auto &dist : all_pairs_distances) {
        cout << "(" << setw(2) << dist.id_1 << ", " << setw(2) << dist.id_2 << ")" << setw(10) << " ";
        cout << "(" << setw(5) << my_double_vector[dist.id_1].x << ", " << setw(5) << my_double_vector[dist.id_1].y << ")";
        cout << ", ";
        cout << "(" << setw(5) << my_double_vector[dist.id_2].x << ", " << setw(5) << my_double_vector[dist.id_2].y << ")" << setw(10) << " ";
        cout << setw(15) << setprecision(4) << dist.cos_distance << endl;
    }
    cout <<endl;

    in_file.close();

    return 0;
}
