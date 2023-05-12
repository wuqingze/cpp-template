#include "utility/CalculateUtility.h"
#include <gtest/gtest.h>

TEST(Utility, Test1) {
    CalculateUtility cal;
    EXPECT_EQ(cal.add(23,20), 43);
}

TEST(Utility, Test2) {
    CalculateUtility cal;
    EXPECT_EQ(cal.add(1,33), 33);
}

TEST(Utility, Test3) {
    CalculateUtility cal;
    EXPECT_EQ(cal.add(0,33), 33);
}
