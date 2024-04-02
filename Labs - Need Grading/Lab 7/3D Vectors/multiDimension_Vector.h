#ifndef _MULTIDIMENSION_VECTOR_H_
#define _MULTIDIMENSION_VECTOR_H_

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct double_vector {
    vector<double> components;
    int id;

    // Default constructor
    double_vector() : id(0) {}

    // Parameterized constructor for a vector of arbitrary dimensions
    double_vector(const vector<double>& components, int id) : components(components), id(id) {}
};

// Function prototypes
double square(const double &d);
double dot_product(const double_vector &one, const double_vector &two);
double magnitude(const double_vector &my_vector);
double cosine_distance(const double_vector &one, const double_vector &two);

#endif
