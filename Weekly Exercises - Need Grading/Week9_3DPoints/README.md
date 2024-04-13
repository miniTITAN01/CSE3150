# WEEK 9 EXERCISE - NEED GRADING  


## **Compiling Instruction** 
0. Ensure that Doctest is installed before running tests

1. Type the following command to compile specific files (**Main Function**, **Unit Tests**)
```bash
        g++ main_triangle.cpp Point3d.cpp Triangle3d.cpp
        g++ unittests.cpp Point3d.cpp Triangle3d.cpp
 
```
2. Run complied files
```bash
        ./a.out
```

## **Problem Clarification**

**Point3d Class:**
- Represents a point in three-dimensional space.
- Contains three private member variables: x, y, and z, which represent the coordinates in 3D space.
- Provides constructors for creating points, including a default constructor, a constructor that sets all coordinates to the same value, and a parameterized constructor for individual coordinates.
- Offers getter and setter methods to access and modify the coordinates.
- Implements the getters as const methods to allow their use on const objects.

**Triangle3d Class:**
- Represents a triangle in 3D space defined by three Point3d objects.
- Contains three Point3d objects as private member variables: p1, p2, and p3, which are the vertices of the triangle.
- Provides constructors for creating triangles, including a default constructor, a copy constructor, and a parameterized constructor that takes three Point3d objects.
- Includes a method to calculate the distance between two points (pointDistance), using the standard Euclidean distance formula in 3D.
- Implements a method to calculate the area of the triangle (getArea) using Heron's formula, which requires the semi-perimeter and the lengths of the sides.
- Overloads the output stream operator (operator<<) to print the coordinates of the triangle's vertices.

## **Exercise Requirements:**
- Read and store 3D coordinates into Point3d objects.
- Use these points to create a Triangle3d object.
- Compute distances between the vertices of the triangle.
- Calculate the area of the triangle using the computed distances and Heron's formula.
- Implement constructors, ostream operators, and setters-getters for both classes.
- Ensure const correctness throughout the class methods to enable their use on const instances.

## **Edge Cases and Testing:**
- Validate that the constructors correctly initialize objects.
- Confirm that distance calculations are accurate in 3D space.
- Ensure that the area calculation handles both regular and degenerate (collinear points) triangles.
- Account for floating-point precision issues in calculations and comparisons.
        




