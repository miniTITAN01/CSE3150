#include <iostream> 

int fact(int n){
    if ( n <= 1){
        return 1;
    }else{
        return n*fact(n-1);
    }
}
int main(){
    //std::cout << "Hello world" << std ::endl;

    using namespace std; //standard namespace

    cout <<"Hello Worlds!" <<endl;

    cout <<"fact(1): "<< fact(1)<<endl;
    cout <<"fact(2): "<< fact(2)<<endl;
    cout <<"fact(3): "<< fact(3)<<endl;
    cout <<"fact(4): "<< fact(4)<<endl;

    return 0;
}

//g++ ex1.cpp -std=c++17