#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "multiDimension_Vector.h" 
#include "distance.h"
#include <algorithm>
#include <vector>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846 // Define M_PI if not defined by <cmath>
#endif

using namespace std;

TEST_CASE("Testing vector operations") {
    // Now using std::vector to initialize double_vector with multiple dimensions
    double_vector v1({3, 4, 0}, 1); // 3D vector with zero as the third component
    double_vector v2({6, 8, 0}, 2); // 3D vector with zero as the third component

    SUBCASE("Test dot_product function") {
        CHECK(dot_product(v1, v2) == doctest::Approx(50.0).epsilon(0.001));
        CHECK(dot_product(v1, v1) == doctest::Approx(25.0).epsilon(0.001)); // Dot product with itself
    }

    SUBCASE("Test magnitude function") {
        CHECK(magnitude(v1) == doctest::Approx(5.0).epsilon(0.001)); // 3-4-5 right triangle
        CHECK(magnitude(v2) == doctest::Approx(10.0).epsilon(0.001)); // 6-8-10 right triangle
    }

    SUBCASE("Test cosine_distance function") {
        // cos_distance between a vector and itself should be 0
        CHECK(cosine_distance(v1, v1) == doctest::Approx(0.0).epsilon(0.001));
        
        // cos_distance between v1(3,4,0) and v2(6,8,0) should be 0 as they are in the same direction
        CHECK(cosine_distance(v1, v2) == doctest::Approx(0.0).epsilon(0.001));
    }

    SUBCASE("Test cosine_distance with vectors of higher dimensions") {
        double_vector v3({1, 1, 1}, 3); // 3D vector
        double_vector v4({1, 1, 0}, 4); // Another 3D vector

        // Known cosine distance from previous example
        double known_cosine_distance = 0.61548;

        // Testing against the known value
        CHECK(cosine_distance(v3, v4) == doctest::Approx(known_cosine_distance).epsilon(0.001));
    }
}

TEST_CASE("Testing sorting of vector pairs by cosine distance") {
    // Create some vectors with IDs
    double_vector v1({1, 2}, 1);
    double_vector v2({2, 4}, 2);
    double_vector v3({-1, -2}, 3);
    double_vector v4({0, 1}, 4);

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
