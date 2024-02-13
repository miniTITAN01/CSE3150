#include <iostream>

using namespace std; 
int test_func(int ( *ptr_to_function)(int)){
    cout << "square: " <<ptr_to_function(5) <<endl;
    return 0;
}

int my_square_function(int x){
    return x*x;

}
int main(){
   

    int (*p_f)(int) = &my_square_function;

    cout << "Pointer to function " <<endl;
    cout << test_func(p_f) <<endl;
    return 0;

}