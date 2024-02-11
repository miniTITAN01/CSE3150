
#include <iostream>

#include <fstream> 

#include "readin_return_int_stack.h"

#include <stack> 

using namespace std;

stack <int> get_ints_from_fie(string file_name){
    ifstream input_file;
    input_file.open("input.txt");

    stack <int> int_stack;

    //checks if the file was successfully opened and returns an error code (1) if it wasn't.
    if (!input_file.is_open()){
        cerr << "Failed to open file." <<endl;
        return 1;
    }

    while (!input_file.eof()) {
      string in_str;
      input_file >> in_str;
      
      int in_int;
      in_int = stroi (in_str);
      int_stack.push(in_int);

      cout << in_int << endl;
    }

    input_file.close();

    return int_stack;

}
