#include <iostream>
#include <stack>
#include <string>

#include "stack_1.h"

using namespace std;


string names[]  = {"S. Ulam", "Alan Turing", "C. Babbage", "Grace Hopper", "Ada Lovelace"};

stack<node> get_stack_node(const int n) {
    stack<node> s;

    int namesCount = sizeof(names) / sizeof(names[0]);

    for (int i=0; i < n; i++) {
        node my_node;
        if (i >= sizeof(names)) { //sizeof(names) = the total size in bytes of the names array
        my_node.name = "Plato";
        my_node.number = i;
        
        s.push(my_node);
        } else {
        node my_node;
        my_node.name = names[i];
        my_node.number = i;
        
        s.push(my_node);
        }
    }

  return s;
}

stack<int> get_stack(const int n) {

  stack<int> s;

  for (int i=0; i < n; i++) {
    s.push(i);
  }

  return s;
}