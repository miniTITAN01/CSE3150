#include "StackQueueFunctions.h"
#include <fstream>
#include <iostream>

std::stack<Item> fillStackFromTextFile(const std::string& filename) {
    std::ifstream file(filename);
    std::stack<Item> s;
    if (!file.is_open()) {
        throw StackQueueException("Failed to open file: " + filename);
    }

    int number;
    while (file >> number) {
        s.push(Item{number});
    }

    return s;
}

std::queue<Item> fillQueueFromTextFile(const std::string& filename) {
    std::ifstream file(filename);
    std::queue<Item> q;
    if (!file.is_open()) {
        throw StackQueueException("Failed to open file: " + filename);
    }

    int number;
    while (file >> number) {
        q.push(Item{number});
    }

    return q;
}

void checkAndPopStack(std::stack<Item>& s) {
    int sum = 0;
    while (!s.empty()) {
        Item item = s.top();
        s.pop();
        sum += item.value;
    }
    if (sum < 0) {
        throw StackQueueException("Negative sum encountered in stack");
    }
}

void checkAndDequeueQueue(std::queue<Item>& q) {
    int sum = 0;
    while (!q.empty()) {
        Item item = q.front();
        q.pop();
        sum += item.value;
    }
    if (sum < 0) {
        throw StackQueueException("Negative sum encountered in queue");
    }
}
