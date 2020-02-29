// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>

template <typename T>
class stack {
    class Node {
    public:
        Node *pNext;
        T data;

        explicit Node(const T& value)
                : pNext(nullptr), data(value)
        {}

        explicit Node(T&& value)
                : pNext(nullptr), data(std::move(value))
        {}

        template<typename... Args>
        explicit Node(Args &&... value)
                : pNext(nullptr), data(std::forward<Args>(value)...)
        {}
    };

    Node *bottom;

public:
    stack(){
        bottom = nullptr;
    }
    ~stack(){
        for (int i = 0; i < this->size(); ++i) {
            pop();
        }
    }
    template <typename ... Args>
    void push_emplace(Args&&... value){
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
    void push(const T& value) {
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
    void push(T&& value) {
        {
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
    }
    const T& head() const {
        Node *current = bottom;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        return current->data;
    }
    T pop(){
        if (this->size() == 0) {
            return 0;
        } else if (this->size() == 1) {
            Node *temp = bottom;
            T back = bottom->data;
            bottom = bottom->pNext;
            delete temp;
            return back;
        } else {
            Node *previous = bottom;
            for (int i = 0; i < this->size() - 2; ++i) {
                previous = previous->pNext;
            }
            Node *current = previous->pNext;
            previous->pNext = current->pNext;
            T back = current->data;
            delete current;
            return back;
        }
    }
    int size(){
        int Size = 0;
        Node* FullStack = bottom;
        while (FullStack != nullptr) {
            FullStack = FullStack->pNext;
            Size++;
        }
        delete FullStack;
        return Size;
    }
};

#endif // INCLUDE_HEADER_HPP_
