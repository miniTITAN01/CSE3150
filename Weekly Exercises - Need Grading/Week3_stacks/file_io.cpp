#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream input_file;
    input_file.open("input.txt");

    //checks if the file was successfully opened and returns an error code (1) if it wasn't.
    if (!input_file.is_open()){
        cerr << "Failed to open file." <<endl;
        return 1;
    }

    while (!input_file.eof()) {
      string in_str;
      input_file >> in_str;
      cout << in_str << endl;
    }

    input_file.close();   
}