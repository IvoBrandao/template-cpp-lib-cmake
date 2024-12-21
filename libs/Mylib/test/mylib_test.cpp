#include "gtest/gtest.h"
#include "mylib.hpp"

namespace MyLibInterface {

// Test case for the add function
TEST(AddFunctionTest, PositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(10, 20), 30);
}

TEST(AddFunctionTest, NegativeNumbers) {
    EXPECT_EQ(add(-2, -3), -5);
    EXPECT_EQ(add(-10, -20), -30);
}

TEST(AddFunctionTest, MixedNumbers) {
    EXPECT_EQ(add(-2, 3), 1);
    EXPECT_EQ(add(10, -20), -10);
}

TEST(AddFunctionTest, ZeroValues) {
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(0, 5), 5);
    EXPECT_EQ(add(5, 0), 5);
}

} // namespace mylib

// Main function to run all tests
// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
