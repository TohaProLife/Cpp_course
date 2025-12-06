#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"
#include <stdexcept>
#include <cstdint>

template <typename T>
class Queue {
private:
    Stack<T> stackIn;
    Stack<T> stackOut;
    std::int64_t maxSize;
    std::int64_t currentSize;

    void transferElements();

public:
    Queue(std::int64_t maxSize);
    void enqueue(T x);
    T dequeue();
    bool isEmpty();
    std::int64_t size();
};

extern template class Queue<int>;
extern template class Queue<float>;
extern template class Queue<double>;
extern template class Queue<char>;

#endif // QUEUE_H