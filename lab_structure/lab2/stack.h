#ifndef STACK_H
#define STACK_H

#include "DynamicArray.h"
#include <stdexcept>
#include <cstdint>

template <typename T>
class Stack {
private:
    DynamicArray array;
    std::int64_t maxSize;
    std::int64_t currentSize;

public:
    Stack(std::int64_t maxSize);
    void push(T x);
    T top();
    T pop();
    bool isEmpty();
};

extern template class Stack<int>;
extern template class Stack<float>;
extern template class Stack<double>;
extern template class Stack<char>;

#endif // STACK_H