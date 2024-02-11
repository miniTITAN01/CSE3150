#include <iostream>
#include <fstream>
#include <stack>
#include <string> // For std::string and std::stoi
#include "readin_return_int_stack.h"

using namespace std;

// Correct the function name typo
stack<int> get_ints_from_file(const string& file_name) {
    ifstream input_file(file_name); // Directly use the file_name parameter

    stack<int> int_stack;

    // Check if the file was successfully opened
    if (!input_file.is_open()) {
        cerr << "Failed to open file: " << file_name << endl;
        throw runtime_error("Failed to open file: " + file_name); // Throw an exception on error
    }

    string in_str;
    while (input_file >> in_str) { // This ensures the loop only processes valid input
        try {
            int in_int = stoi(in_str); // Convert string to int
            int_stack.push(in_int);
            // Removing the cout line will make the function adhere to single responsibility principle
        } catch (const invalid_argument& e) {
            cerr << "Invalid integer in file: " << in_str << endl;
            // Optionally handle the error, e.g., skip the invalid input
        } catch (const out_of_range& e) {
            cerr << "Integer out of range in file: " << in_str << endl;
            // Optionally handle the error
        }
    }

    input_file.close();
    return int_stack;
}

/*#include <iostream>

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
      in_int = stoi (in_str);
      int_stack.push(in_int);

      cout << in_int << endl;
    }

    input_file.close();

    return int_stack;

}*/
