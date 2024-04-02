
#include <iostream>
#include <cmath>

#include "multiDimension_Vector.h"


using namespace std;


double square(const double & d){
    return d*d;
}

double dot_product(const double_vector & one, const double_vector & two) {
    double result = 0.0;
    for (size_t i = 0; i < one.components.size(); i++) {
        result += one.components[i] * two.components[i];
    }
    return result;
}

double magnitude(const double_vector & my_vector) {
    double sum = 0.0;
    for (double val : my_vector.components) {
        sum += square(val);
    }
    return sqrt(sum);
}


double cosine_distance(const double_vector & one, const double_vector & two) {
    double dot = dot_product(one, two);
    double magOne = magnitude(one);
    double magTwo = magnitude(two);
    double cos_similarity = dot / (magOne * magTwo);
    // Ensure the result is within the valid range for acos
    cos_similarity = max(-1.0, min(1.0, cos_similarity));
    // Returning the acos of the similarity gives the angle in radians, which is a measure of distance
    return acos(cos_similarity);
}


