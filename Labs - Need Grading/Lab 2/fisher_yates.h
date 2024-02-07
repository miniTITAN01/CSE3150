
#ifndef _FISHER_YATES_H_
#define _FISHER_YATES_H_

void print_array( int array[], int len);
int swap (int* first, int* second);

bool is_well_balanced(int array[], int length);
bool hasMoreClosingsThanOpenings(int array[], int length);
bool hasMoreOpeningsThanClosings (int array[], int length);

void fisherYatesShuffle(int array[], const int length);

#endif