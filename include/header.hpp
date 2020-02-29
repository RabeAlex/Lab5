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

#endif // INCLUDE_HEADER_HPP_
