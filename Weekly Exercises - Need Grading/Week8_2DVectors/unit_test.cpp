#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "double_Vector.h" 
#include "distance.h"
#include <algorithm>
#include <vector>

#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846 // Define M_PI if not defined by <cmath>
#endif



TEST_CASE("Testing vector operations") {
    double_vector v1(3, 4, 1);
    double_vector v2(6, 8, 2);

    SUBCASE("Test square function") {
        CHECK(square(3.0) == 9.0);
        CHECK(square(-3.0) == 9.0);
        CHECK(square(0.0) == 0.0);
    }

    SUBCASE("Test dot_product function") {
        CHECK(dot_product(v1, v2) == 50.0);
        CHECK(dot_product(v1, v1) == 25.0); // Dot product with itself
    }

    SUBCASE("Test magnitude function") {
        CHECK(magnitude(v1) == 5.0); // 3-4-5 right triangle
        CHECK(magnitude(v2) == 10.0); // 6-8-10 right triangle
    }

    SUBCASE("Test cosine_distance function") {
        // cos_distance between a vector and itself should be 0
        CHECK(cosine_distance(v1, v1) == doctest:: Approx(0.0).epsilon(0.001));
        
        // cos_distance between v1(3,4) and v2(6,8) should be 0 as they are in the same direction
        CHECK(cosine_distance(v1, v2) == doctest:: Approx(0.0).epsilon(0.001));
        
        //EXAMPLE FROM PROFESSOR 
        double_vector v3(3, 7, 3);
        double_vector v4(10, 6, 4);  
        
        CHECK(cosine_distance(v3, v4) ==  doctest:: Approx(0.625485).epsilon(0.001));
    }


}

TEST_CASE("Testing sorting of vector pairs by cosine closeness") {
    // Create some vectors with IDs
    double_vector v1(1, 2, 1);
    double_vector v2(2, 4, 2);
    double_vector v3(-1, -2, 3);
    double_vector v4(0, 1, 4);

    // Initialize a vector to store distances
    std::vector<my_distance> distances;

    // Calculate distances between all pairs (assuming cosine closeness means cosine similarity)
    distances.push_back({1, 2, cosine_distance(v1, v2)});
    distances.push_back({1, 3, cosine_distance(v1, v3)});
    distances.push_back({1, 4, cosine_distance(v1, v4)});
    distances.push_back({2, 3, cosine_distance(v2, v3)});
    distances.push_back({2, 4, cosine_distance(v2, v4)});
    distances.push_back({3, 4, cosine_distance(v3, v4)});

    // Sort distances by cosine distance (closeness)
    std::sort(distances.begin(), distances.end(),
              [](const my_distance& a, const my_distance& b) {
                  return a.cos_distance < b.cos_distance;
              });

    // Now check if each element in the sorted array has a cosine distance
    // less than or equal to the next element, which would confirm correct sorting.
    for (size_t i = 0; i < distances.size() - 1; ++i) {
        CHECK(distances[i].cos_distance <= distances[i + 1].cos_distance);
    }
}
