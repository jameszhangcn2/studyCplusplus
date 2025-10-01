#include "hello_world.h"
#include <gtest/gtest.h>

TEST(HelloWorldTest, BasicOutput) {
    string name = "World";
    string output = hello(name);
    EXPECT_EQ(output, "Hello World!");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
