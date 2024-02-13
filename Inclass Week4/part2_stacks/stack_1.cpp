#include <iostream>
#include <stack>
#include <string>
#include "stack_1.h"

using namespace std;

string names[] = {"S. Ulam", "Alan Turing", "C. Babbage", "Grace Hopper", "Ada Lovelace"};

stack<node> get_stack_node(const int n) {
    stack<node> s;

    // Correct calculation for the number of elements in the names array
    int namesCount = sizeof(names) / sizeof(names[0]);

    for (int i = 0; i < n; i++) {
        node my_node;

        if (i < namesCount) {
            my_node.name = names[i];
        } else {
            my_node.name = "Plato";
        }

        my_node.number = i;
        s.push(my_node);
    }

    return s;
}

stack<int> get_stack(const int n) {
    stack<int> s;

    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    return s;
}
