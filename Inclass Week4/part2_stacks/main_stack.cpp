
#include <iostream> 

#include "readin_return_int_stack.h"
#include <stack>

using namespace std;

int main(){

    stack<int> s = get_ints_from_fie("input.txt")

    int array_len = s.size();
    int array_for_prefix_sum[array_len] ;

    int position = 0; 
    while (!s.empty()){
        array_for_prefix_sum[position] = s.top();
        s.pop();

    }

    if(non_negative_prefix_sum(array_for_prefix_sum, array_len)){
        cout <<"non-negative" <<endl;
    }else{
        cout << "negative" <<endl;
    }
    return 0;
}