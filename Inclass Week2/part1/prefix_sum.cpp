#include <iostream>
#include "prefix_sum.h"


int prefix_sum(int array[], int length){
    int sum = 0;
    
    for (int i = 0; i < length; i++){
        sum += array[i];
    }

    return sum;
}

bool non_negative_prefix_sum(int array[], int length){
    //bool negative_found = false;
    int sum = 0; 

    for (int i =0; i < length; i++){
        sum += array[i];
        if (sum < 0){
            //negative_found = true;
            //break;
            return false; //if sum goes below zero, return false immediately
        }
    }

    //return negative_found;
    return true; //if the loop completes without sum going below zero
}

bool non_positive_prefix_sum(int array[], int length){
    int sum = 0; 

    for (int i =0; i < length; i++){
        sum += array[i];
        if (sum > 0){
            return false; //if sum goes above zero, return false immediately
        }
    }
    return true; //if the loop completes without sum going above zero
}