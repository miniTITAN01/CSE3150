#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "multiDimension_Vector.h" 
#include "distance.h"
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

TEST_CASE("Testing vector operations with 5D vectors") {
    // Creating 5-dimensional vectors
    double_vector v1({1, 2, 3, 4, 5}, 1);
    double_vector v2({5, 4, 3, 2, 1}, 2);
    double_vector v3({2, 3, 4, 5, 6}, 3);
    double_vector v4({-1, -1, -1, -1, -1}, 4);

    SUBCASE("Test dot_product function with 5D vectors") {
        // The dot product of v1 and v2 would be 1*5 + 2*4 + 3*3 + 4*2 + 5*1
        CHECK(dot_product(v1, v2) == doctest::Approx(35).epsilon(0.001));
        // Dot product of v1 with itself
        CHECK(dot_product(v1, v1) == doctest::Approx(55).epsilon(0.001));
    }

    SUBCASE("Test magnitude function with 5D vectors") {
        // Magnitude of v1 would be sqrt(1^2 + 2^2 + 3^2 + 4^2 + 5^2)
        CHECK(magnitude(v1) == doctest::Approx(sqrt(55)).epsilon(0.001));
        // Magnitude of v4 (all components are -1)
        CHECK(magnitude(v4) == doctest::Approx(sqrt(5)).epsilon(0.001));
    }

    SUBCASE("Test cosine_distance function with 5D vectors") {
        // cos_distance between v1 and v2 for 5D vectors
        double expected_cos_distance = acos(dot_product(v1, v2) / (magnitude(v1) * magnitude(v2)));
        CHECK(cosine_distance(v1, v2) == doctest::Approx(expected_cos_distance).epsilon(0.001));
        
        // cos_distance between a vector and itself should be 0
        CHECK(cosine_distance(v1, v1) == doctest::Approx(0.0).epsilon(0.001));
    }
}

TEST_CASE("Testing sorting of 5D vector pairs by cosine distance") {
    // Create some 5D vectors with IDs
    double_vector v1({1, 2, 3, 4, 5}, 1);
    double_vector v2({5, 4, 3, 2, 1}, 2);
    double_vector v3({2, 3, 4, 5, 6}, 3);
    double_vector v4({-1, -1, -1, -1, -1}, 4);

    // Initialize a vector to store distances
    std::vector<my_distance> distances;

    // Calculate distances between all pairs
    distances.push_back({1, 2, cosine_distance(v1, v2)});
    distances.push_back({1, 3, cosine_distance(v1, v3)});
    distances.push_back({1, 4, cosine_distance(v1, v4)});
    distances.push_back({2, 3, cosine_distance(v2, v3)});
    distances.push_back({2, 4, cosine_distance(v2, v4)});
    distances.push_back({3, 4, cosine_distance(v3, v4)});

    // Sort distances by cosine distance
    sort(distances.begin(), distances.end(),
              [](const my_distance& a, const my_distance& b) {
                  return a.cos_distance < b.cos_distance;
              });

    // Check if the distances are sorted correctly
    for (size_t i = 0; i < distances.size() - 1; ++i) {
        CHECK(distances[i].cos_distance <= distances[i + 1].cos_distance);
    }
}
