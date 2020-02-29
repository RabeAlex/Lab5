// Copyright 2018 Your Name <your_email>
#include <iostream>
#include <header.hpp>

template <typename T>
class stack {
    class Node {
    public:
        Node *pNext;
        T data;

        explicit Node(const T& value)
                : data(value), pNext(nullptr)
        {}

        explicit Node(T&& value)
                : data(std::move(value)), pNext(nullptr)
        {}

        template<typename... Args>
        explicit Node(Args &&... value)
                : data(std::forward<Args>(value)...), pNext(nullptr)
        {}
    };

    Node *bottom;

public:
    stack();
    ~stack();

    template <typename ... Args>
    void push_emplace(Args&&... value);
    void push(const T& value);
    void push(T&& value);
    const T& head() const;
    T pop();
    int size();
};

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


int main() {

    return 0;
}