// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "header.hpp"

TEST(stack, Text) {
    stack<int> test;
    test.push_emplace(1);
    test.push(2);
    test.push_emplace(3);
    EXPECT_EQ(std::is_move_constructible<stack<int>>::value, true);
    EXPECT_EQ(std::is_move_assignable<stack<int>>::value, true);
    EXPECT_EQ(test.head(), 3);
    EXPECT_EQ(test.pop(), 3);
    EXPECT_EQ(test.head(), 2);
    EXPECT_EQ(test.pop(), 2);
    EXPECT_EQ(test.head(), 1);
    EXPECT_EQ(test.pop(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
