
#include <iostream> 
#include "fisher_yates.h"

void print_array( int array[], int len){

    for (int i = 0; i <len; i++){
        std ::cout << array[i] << " ";

    }

    std:: cout << std:: endl;
}

int swap (int* first, int* second){
    int temp = *first;
    *first = *second; 
    *second = temp;

    return 0;
}

//IMPROVED VERSION OF FISHER_YATES
/*void fisher_yates(int array[], const int length, int (*random_fcn)()){
    for (int i = length - 1; i > 0 ; i--){
        //int rnd_location = random_fcn()% (i+1);

        // Generate a random index from 0 to i
        int rnd_location = rand() % (i + 1);

        swap(&array[i], &array[rnd_location]);
    }
}*/

//MY OWN VERSION OF FISHER_YATES
void fisherYatesShuffle(int array[], int size) {

    for (int i = size - 1; i > 0; --i) {
        // Generate a random position within [0, i]
        int j = std::rand() % (i + 1);

        // Swap elements at positions i and j
        swap(&array[i], &array[j]);
    }
}

//IMPLEMENT VALIDATON FOR WELL-BALANCED LISTS
bool is_well_balanced(int array[], int length){
    int sum = 0;
    for (int i = 0; i < length; i ++){
        sum += array[i];
        if (sum < 0) return false;  //terminate if sum is negative/ not balanced list/closing paren > opening paren
    }
    return sum == 0;
}

/*NOTE: A sequence of parentheses can be considered well-balanced if, at any point, 
the number of closing parentheses does not exceed the number of opening parentheses (non-negative prefix sum condition) 
and ends with an equal number of opening and closing parentheses (sum equals 0). 
The "non-positive prefix sums" part does not directly apply to the context of balanced parentheses, 
as having more closing than opening parentheses at any point would make a sequence unbalanced.*/

//NEGATIVE PREFIX SUM (non_positive) - MORE CLOSING THAN OPENING - imbalanced
bool hasMoreClosingsThanOpenings(int array[], int length){
    int sum =0;
    for (int i =0; i < length; i++){
        sum+=array[i];
        if (sum<0){
            return true; //closing > opening = imbalanced
        }
    }
    return false; //no point where closing exceed opening
}
//the number of closing parentheses does not exceed the number of opening parentheses
//POSITIVE PREFIX SUM (non_negative) - 
bool hasMoreOpeningsThanClosings(int array[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    return sum > 0; // True if imbalance, false if balanced
}



