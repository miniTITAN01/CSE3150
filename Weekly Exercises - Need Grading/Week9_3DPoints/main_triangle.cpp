#include <iostream>

#include "Triangle3d.h"

using namespace std;

int main() {
    Point3d p1(0.0, 0.0, 0.0);
    Point3d p2(1.0, 2.0, 0.0);
    Point3d p3(-1.0, 0.0, 0.0);

    Triangle3d triangle(p1, p2, p3);

    // Display the distance between points p1 and p2 for verification
    cout << "Distance between p1 and p2: " << triangle.pointDistance(p1, p2) << endl;
    cout << "That should have been the sqrt(5) = sqrt(1^2 + 2^2)" << endl;

    // Display the area of the triangle
    cout << "The area of the triangle is: " << triangle.getArea() << endl;

    return 0;
}