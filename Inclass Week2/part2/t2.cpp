

#include <iostream>

#define FCN(x) {x++; };

int main(){
    using namespace std;

    int a = 5, b = 10;
    FCN(a)
    FCN(b)

    FCN(a+b) //a = 6, b = 11 and +b = 12
    cout << "a is " 
         << a
         << " b is " 
         << b 
         << " a + b is " 
         << a + b 
         << endl;


    return 0;
}