#include <iostream>
#include "lambdas_Operations.h"
using namespace std; 

int main() {
    vector<int> vect = {6, 28, 496, 8128,10, 2, 3, 36, 999, 1, 17, 13, -4, 5, 66, 7, 8};

    cout << "----Input------------" << endl;
    display(vect);

    cout << "----Sorted------------" << endl;
    sort_and_display(vect);

    cout << "----Evens------------" << endl;
    evens(vect);

    cout << "----Divides by 2 and 3------------" << endl;
    // Check divisibility by 1, 2, and 3
    divides_by(vect, 2);
    divides_by(vect, 3);
    cout << endl;
    cout << "Divides by then set d = 1"<<endl;
    int d = 3;
    divides_by_then_set_d_1(vect, d);
    cout << "d = " << d << endl;

    cout << "----Perfect Numbers Check------------" << endl;
    check_perfect_numbers(vect);

    return 0;
}
