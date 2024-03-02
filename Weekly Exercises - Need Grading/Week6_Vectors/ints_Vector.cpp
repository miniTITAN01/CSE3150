#include "ints_Vector.h"

int_vector::int_vector() : id(-1), from(0), to(0) {} // Default constructor

int_vector::int_vector(const int_vector &i_v) : id(i_v.id), from(i_v.from), to(i_v.to) {} // Copy constructor

// Parameterized constructor
int_vector::int_vector(int id_val, int from_val, int to_val) : id(id_val), from(from_val), to(to_val) {}
