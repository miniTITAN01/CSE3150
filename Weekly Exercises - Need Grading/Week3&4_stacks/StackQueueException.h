#ifndef STACK_QUEUE_EXCEPTION_H
#define STACK_QUEUE_EXCEPTION_H

#include <stdexcept>
#include <string>

class StackQueueException : public std::runtime_error {
public:
    StackQueueException(const std::string& message)
        : std::runtime_error(message) {}
};

#endif // STACK_QUEUE_EXCEPTION_H
