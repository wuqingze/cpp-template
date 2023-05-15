#include "foo.h"
#include <stdio.h>
#include "SingleInstance.h"
#include <gtest/gtest.h>

TEST(FooTest, Test1) {
    EXPECT_EQ(add(11,22), 43);
}

TEST(FooTest, Test2) {
    EXPECT_EQ(33, 33);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
