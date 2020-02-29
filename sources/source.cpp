// Copyright 2018 Your Name <your_email>

#include <header.hpp>

template<typename T>
stack<T>::stack() {
    bottom = nullptr;
}

template<typename T>
stack<T>::~stack() {
    for (size_t i = 0; i < this->size(); ++i) {
        pop();
    }
}

template<typename T>
void stack<T>::push(T &&value) {
    if (bottom == nullptr) {
        bottom = new Node(std::move(value));
    } else {
        Node *current = bottom;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node(std::move(value));
    }
}

template<typename T>
void stack<T>::push(const T &value) {
    if (bottom == nullptr) {
        bottom = new Node(value);
    } else {
        Node *current = bottom;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node(value);
    }
}

template<typename T>
template<typename... Args>
void stack<T>::push_emplace(Args &&... value) {
    if (bottom == nullptr) {
        bottom =  new Node(std::forward<Args>(value)...);
    } else {
        Node *current = bottom;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node(std::forward<Args>(value)...);
    }
}

template<typename T>
const T &stack<T>::head() const {
    Node *current = bottom;
    while (current->pNext != nullptr) {
        current = current->pNext;
    }
    return current->data;
}

template<typename T>
T stack<T>::pop() {
    if (this->size() == 1){
        Node *temp = bottom;
        T back = bottom->data;
        bottom = bottom->pNext;
        delete temp;
        return back;
    } else if (this->size() != 0) {
        Node *previous = bottom;
        for (size_t i = 0; i < this->size() - 2; ++i) {
            previous = previous->pNext;
        }
        Node *current = previous->pNext;
        previous->pNext = current->pNext;
        T back = current->data;
        delete current;
        return back;
    }
}

template<typename T>
int stack<T>::size() {
    int Size = 0;
    Node* FullStack = bottom;
    while (FullStack != nullptr) {
        FullStack = FullStack->pNext;
        Size++;
    }
    delete FullStack;
    return Size;
}
