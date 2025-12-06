#include "queue.h"

template <typename T>
void Queue<T>::transferElements() {
    while (!this->stackIn.isEmpty()) {
        this->stackOut.push(this->stackIn.pop());
    }
}

template <typename T>
Queue<T>::Queue(std::int64_t maxSize) : stackIn(maxSize), stackOut(maxSize), 
                                       maxSize(maxSize), currentSize(0) {}

template <typename T>
void Queue<T>::enqueue(T x) {
    if (currentSize >= maxSize) {
        throw std::runtime_error("overflow");
    }
    stackIn.push(x);
    currentSize++;
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("underflow");
    }
    if (stackOut.isEmpty()) {
        this->transferElements();
    }
    currentSize--;
    return stackOut.pop();
}

template <typename T>
bool Queue<T>::isEmpty() {
    return currentSize == 0;
}

template <typename T>
std::int64_t Queue<T>::size() {
    return currentSize;
}

template class Queue<int>;
template class Queue<float>;
template class Queue<double>;
template class Queue<char>;