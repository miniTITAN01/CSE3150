#ifndef GEN_PERMUTATION_H_  // Use an underscore at the end to avoid starting with an underscore and a capital letter
#define GEN_PERMUTATION_H_

#include <vector>

void compute_permutation_of_array(int array[], int length);
int get_lowest_prefix_sum_value(const int array[], int length); // Correct as is
int index_of_lowest_prefix_sum_element(const int array[], int length); // Now accepts a const int*

#endif // GEN_PERMUTATION_H_
