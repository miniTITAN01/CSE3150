#ifndef STACK_QUEUE_FUNCTIONS_H
#define STACK_QUEUE_FUNCTIONS_H

#include <stack>
#include <queue>
#include "Item.h"
#include "StackQueueException.h"

std::stack<Item> fillStackFromTextFile(const std::string& filename);
std::queue<Item> fillQueueFromTextFile(const std::string& filename);

void checkAndPopStack(std::stack<Item>& s);
void checkAndDequeueQueue(std::queue<Item>& q);

#endif // STACK_QUEUE_FUNCTIONS_H
