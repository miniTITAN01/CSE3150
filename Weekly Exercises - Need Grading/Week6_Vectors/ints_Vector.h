#ifndef INTS_VECTOR_H
#define INTS_VECTOR_H

struct int_vector {
    int id;
    int from;
    int to;

    int_vector(); // Default constructor
    int_vector(const int_vector &i_v); // Copy constructor
    int_vector(int id, int from, int to); // Parameterized constructor
};

#endif // INTS_VECTOR_H



//


