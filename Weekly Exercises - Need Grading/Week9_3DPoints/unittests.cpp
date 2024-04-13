#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Point3d.h"
#include "Triangle3d.h"

TEST_CASE("Testing Point3d Class") {
    SUBCASE("Default Constructor") {
        Point3d p;
        CHECK(p.get_x() == doctest::Approx(0.0));
        CHECK(p.get_y() == doctest::Approx(0.0));
        CHECK(p.get_z() == doctest::Approx(0.0));
    }

    SUBCASE("Parameterized Constructor") {
        Point3d p(1.0, 2.0, 3.0);
        CHECK(p.get_x() == doctest::Approx(1.0));
        CHECK(p.get_y() == doctest::Approx(2.0));
        CHECK(p.get_z() == doctest::Approx(3.0));
    }

    SUBCASE("Copy Constructor") {
        Point3d p1(4.0, 5.0, 6.0);
        Point3d p2(p1);
        CHECK(p2.get_x() == doctest::Approx(4.0));
        CHECK(p2.get_y() == doctest::Approx(5.0));
        CHECK(p2.get_z() == doctest::Approx(6.0));
    }
}

TEST_CASE("Testing Triangle3d Class") {
    Point3d p1(0.0, 0.0, 0.0);
    Point3d p2(1.0, 0.0, 0.0);
    Point3d p3(0.0, 1.0, 0.0);
    Point3d p4(0.0, 0.0, 1.0);

    Triangle3d t1(p1, p2, p3);

    SUBCASE("Distance Calculation") {
        CHECK(t1.pointDistance(p1, p2) == doctest::Approx(1.0));
        CHECK(t1.pointDistance(p1, p3) == doctest::Approx(1.0));
        CHECK(t1.pointDistance(p2, p3) == doctest::Approx(sqrt(2.0)));
    }

    SUBCASE("Area Calculation") {
        Triangle3d t3(p2, p3, p4);
        CHECK(t3.getArea() == doctest::Approx(sqrt(3)/2)); 
    }


    SUBCASE("Area of Degenerate Triangle") {
        Point3d degenerate_p3(0.5, 0.0, 0.0); // Lies on the line between p1 and p2
        Triangle3d degenerate_triangle(p1, p2, degenerate_p3);
        CHECK(degenerate_triangle.getArea() == doctest::Approx(0.0));
    }

    SUBCASE("Triangles with Negative Coordinates") {
        Point3d neg_p1(-1.0, -1.0, 0.0);
        Point3d neg_p2(-2.0, -1.0, 0.0);
        Point3d neg_p3(-1.5, -0.5, 0.0);
        Triangle3d neg_triangle(neg_p1, neg_p2, neg_p3);
        CHECK(neg_triangle.getArea() == doctest::Approx(0.25));
    }
}
