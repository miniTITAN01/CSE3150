#include <iostream>
#include "prefix_sum.h"

int main(){

    std ::cout <<"Hello World!" <<std::endl;

    int array0[] = {1, -1, 1, 1, -1, -1, 19, 20};
    int sum = prefix_sum(array0, sizeof(array0)/sizeof(array0[0]));

    std ::cout << "Prefix sum is: " << sum << std:: endl;

    int array1[] = {1, -1, 1, -1};
    std:: cout << "Array 1: ";
    std:: cout << (non_negative_prefix_sum(array1, 4) ? "true" : "false") << std::endl;
    std:: cout << (non_positive_prefix_sum(array1, 4) ? "true" : "false") << std::endl;

    int array2[] = {1, -1, -1 , 1};
    std:: cout << "Array 2: ";
    std:: cout << (non_negative_prefix_sum(array2, 4) ? "true" : "false") <<std ::endl;
    std:: cout << (non_positive_prefix_sum(array2, 4) ? "true" : "false") <<std ::endl;

    int array3[] = {1, -2};
    std:: cout << "Array 3: ";
    std:: cout << (non_negative_prefix_sum(array3, 2) ? "true" : "false") <<std ::endl;
    std:: cout << (non_positive_prefix_sum(array3, 2) ? "true" : "false") <<std ::endl;


    return 0; 
}