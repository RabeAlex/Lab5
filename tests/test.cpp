// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "header.hpp"

int main() {
    stack<int> test;
    int a = 2, b = 3, c = 4;

    test.push(a);
    test.push(b);
    test.push(c);
    test.push(12);
    test.push_emplace(15);

    std::cout << std::is_move_assignable<stack<int>>::value << std::endl;
    std::cout << std::is_move_constructible<stack<int>>::value << std::endl;

    std::cout << test.head() << std::endl;
    std::cout << test.pop() << std::endl;
    std::cout << test.pop() << std::endl;
    std::cout << test.pop() << std::endl;
    std::cout << test.pop() << std::endl;
    std::cout << test.pop() << std::endl;

    return 0;
}
