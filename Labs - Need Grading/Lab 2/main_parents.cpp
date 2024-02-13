
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "fisher_yates.h"

using namespace std;

//FUNCTION GENERATE A RANDOM NUMBER
int random_function(){
    return rand(); //returns a random number using rand()
}

int main() {

    //srand(time(NULL)); // Seed the random number generator
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    string n_string;
    cout << "Enter the number of open-parens: ";
    cin >> n_string;

    int n;

    n = stoi(n_string);

    //Total attempts to generate sequences
    int trials = 20000;
    //Count of well-balanced sequences
    int validSequence = 0;
    //Count of invalid sequences
    //int invalidSequence = 0;

    int moreOpeningsThanClosings = 0;
    int moreClosingsThanOpenings = 0;
    
    for (int attempt = 0; attempt < trials; attempt++){
        //1. GIVEN A LIST OF 2N INTERGER
        int arrayValues[2*n];

        //1. FILL THE FIRST N ELEMENTS WITH 1 AND THE NEXT N ELEMENT WITH -1
        for (int i=0; i < n; i++) {
            arrayValues[i] = 1;
            arrayValues[i+n] = -1;
        }
        
        /*cout << "Original Array: ";
        print_array(arrayValues, 2*n) ;
        cout <<endl;*/

        //2. SHUFFLE THE ARRAY
        fisherYatesShuffle(arrayValues, 2*n);

        /*cout << "Shuffled Array: ";
        print_array(arrayValues, 2*n);
        cout <<endl;*/

        //3. Toss out any scrambled lists that do not have non-negative or non-positive prefix sums
        
        if (is_well_balanced(arrayValues, 2*n)) {
            validSequence++;
        } else {
            if (hasMoreClosingsThanOpenings(arrayValues, 2*n)) {
                moreClosingsThanOpenings++;
            } else if (hasMoreOpeningsThanClosings(arrayValues, 2*n)) {
                moreOpeningsThanClosings++;
            }
        } 
        }
    double proportionValid = static_cast<double>(validSequence) / trials;
    double proportionMoreOpenings = static_cast<double>(moreOpeningsThanClosings) / trials;
    double proportionMoreClosings = static_cast<double>(moreClosingsThanOpenings) / trials;

    cout << endl;
    cout << "Total sequences generated: " << trials << endl;
    cout << "Total well-balanced sequences: " << validSequence << endl;
    cout << "Proportion of valid sequences: " << proportionValid << endl;
    cout << endl;
    cout << "Total sequences with more openings than closings: " << moreOpeningsThanClosings << endl;
    cout << "Proportion of sequences with more openings than closings: " << proportionMoreOpenings << endl;
    cout << endl;
    cout << "Total sequences with more closings than openings at any point: " << moreClosingsThanOpenings << endl;
    cout << "Proportion of sequences with more closings than openings at any point: " << proportionMoreClosings << endl;

    return 0;
}

/*
NOTE: The absence of sequences with "more openings than closings" is expected based on how you're generating 
and shuffling your sequences. The approach ensures an equal number of each type, 
with shuffling only affecting the order, not the count. Thus, every sequence either becomes well-balanced 
(if the order is correct) or fails to be well-balanced due to the order of parentheses, 
not because there are inherently more openings than closings.
*/

