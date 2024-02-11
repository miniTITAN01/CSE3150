#include "StackQueueFunctions.h"
#include <iostream>

int main() {
    try {
        auto s = fillStackFromTextFile("input.txt");
        checkAndPopStack(s); // This might throw if the sum is negative
        std::cout << "Stack processed successfully.\n";
    } catch (const StackQueueException& e) {
        std::cerr << "Stack error: " << e.what() << std::endl;
    }

    try {
        auto q = fillQueueFromTextFile("input.txt");
        checkAndDequeueQueue(q); // This might throw if the sum is negative
        std::cout << "Queue processed successfully.\n";
    } catch (const StackQueueException& e) {
        std::cerr << "Queue error: " << e.what() << std::endl;
    }

    return 0;
}
