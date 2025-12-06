#include "stack.h"

template <typename T>
Stack<T>::Stack(std::int64_t maxSize) : array(maxSize), maxSize(maxSize), currentSize(0) {}

template <typename T>
void Stack<T>::push(T x) {
    if (this->currentSize >= this->maxSize) {
        throw std::runtime_error("overflow");
    }
    this->array.push_back(static_cast<float>(x));
    this->currentSize++;
}

template <typename T>
T Stack<T>::top() {
    if (isEmpty()) {
        throw std::runtime_error("empty stack");
    }
    return static_cast<T>(this->array.back());
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::runtime_error("empty stac");
    }
    T value = static_cast<T>(this->array.back());
    this->array.delete_idx(currentSize - 1);
    this->currentSize--;
    return value;
}

template <typename T>
bool Stack<T>::isEmpty() {
    return currentSize == 0;
}

template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<char>;