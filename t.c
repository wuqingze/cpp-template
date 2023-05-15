#include <stdio.h>
#include <string.h>

void test00(int arr[]){
    printf("sizeof(arr): %zu--\n", sizeof(arr)); // 输出：14（包括空字符）
}

int main() {
    int arr[] = {1,2,3};
    char str[] = "Hello, world!";
    char *str_ptr = str;

    // sizeof 的使用
    printf("sizeof(str): %zu\n", sizeof(str)); // 输出：14（包括空字符）
    printf("sizeof(str_ptr): %zu\n", sizeof(str_ptr)); // 输出：指针大小（通常是 4 或 8）

    // strlen 的使用
    printf("strlen(str): %zu\n", strlen(str)); // 输出：13（不包括空字符）

    printf("sizeof(arr): %zu\n", sizeof(arr)); // 输出：14（包括空字符）
    test00(arr);
    return 0;
}
