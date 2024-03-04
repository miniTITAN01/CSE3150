#include "lambdas_Operations.h"
#include <algorithm>
#include <numeric> // For std::accumulate

using namespace std;

void display(const vector<int>& vect) {
    for_each(vect.begin(), vect.end(),
             [](int elt) { cout << elt << " "; });
    cout << endl;
}

void sort_and_display(vector<int>& vect) {
    sort(vect.begin(), vect.end(), [](const int& left, const int& right) { return left > right; });
    display(vect);
}

void evens(const vector<int>& vect) {
    for_each(vect.begin(), vect.end(), [](int elt) { if (elt % 2 == 0) cout << elt << " "; });
    cout << endl;
}

void divides_by(const vector<int>& vect, const int& d) {
    for_each(vect.begin(), vect.end(), [d](int elt) { if (elt % d == 0) cout << elt << " "; });
    cout << endl;
}

void divides_by_then_set_d_1(const vector<int>& vect, int& d) {
    for_each(vect.begin(), vect.end(), [&d](int elt) mutable { cout << elt << " "; d = 1; });
    cout << endl;
}

bool is_perfect_number(int n) {
    if (n < 1) return false;
    int sum = 0;
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) sum += i;
    }
    return sum == n;
}

void check_perfect_numbers(const vector<int>& vect) {
    vector<int> perfectNumbers, notPerfectNumbers;

    // Separate numbers into perfect and non-perfect
    for_each(vect.begin(), vect.end(), [&](int elt) {
        if (is_perfect_number(elt)) {
            perfectNumbers.push_back(elt);
        } else {
            notPerfectNumbers.push_back(elt);
        }
    });

    // Print perfect numbers
    cout << "Perfect numbers: ";
    for_each(perfectNumbers.begin(), perfectNumbers.end(), [](int elt) {
        cout << elt << " ";
    });
    cout << endl;

    // Print non-perfect numbers
    cout << "Non-perfect numbers: ";
    for_each(notPerfectNumbers.begin(), notPerfectNumbers.end(), [](int elt) {
        cout << elt << " ";
    });
    cout << endl;
}
