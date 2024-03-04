#ifndef _LAMBDAS_OPERATIONS_H
#define _LAMBDAS_OPERATIONS_H

#include <vector>
#include <iostream>

void display(const std::vector<int>& vect);
void sort_and_display(std::vector<int>& vect);
void evens(const std::vector<int>& vect);
void divides_by(const std::vector<int>& vect, const int& d);
void divides_by_then_set_d_1(const std::vector<int>& vect, int& d);
bool is_perfect_number(int n);
void check_perfect_numbers(const std::vector<int>& vect);

#endif // OPERATIONS_H
