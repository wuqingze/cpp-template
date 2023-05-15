#include <gtest/gtest.h>
#include <stdio.h>

TEST(ConstTest, test1) {
    printf("--------- %d\n", __LINE__);
    char *p = "Hello, world!";
    printf("--------- %d\n", __LINE__);
    //p[0] = 'M'; // 修改指针所指向的值
    printf("--------- %d\n", __LINE__);
    p++; // 修改指针本身
    printf("--------- %d %s\n", __LINE__, p);
    EXPECT_EQ(2, 3);
}

TEST(ConstTest, test2) {
    char str[] = "Hello, world!";
    char * const p = str;
    p[0] = 'M'; // 可以修改指针所指向的值
// p++; // 错误：不能修改指针本身
    EXPECT_EQ(33, 34);
}
