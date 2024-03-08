#include <iostream>
#include <istream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

#include "ints_write.h"



int main() {
    using namespace std;

    ifstream in_file;
    
    in_file.open("graph_0.txt");

    vector<int> my_vector;

    for (string str; in_file >> str;) {
        my_vector.push_back(stoi(str));
    }
    cout << my_vector << endl;
  
    in_file.close();

    return 0;
}