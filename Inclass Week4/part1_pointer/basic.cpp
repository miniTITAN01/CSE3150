#include <iostream>

int main(){
    using namespace std;

    int *px = new int;

    *px = 25; 

    cout << "*px= " << *px << endl; //dereference 
    cout << "px= " << px << endl; //adress

    delete px;
    return 0;

}