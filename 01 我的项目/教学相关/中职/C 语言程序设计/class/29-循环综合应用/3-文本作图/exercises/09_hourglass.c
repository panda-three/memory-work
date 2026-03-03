#include <stdio.h>

/*
 * 题目10：打印沙漏图案
 */
int main() {
    int n = 5;  // 高度
    int i, j;

    printf("沙漏图案:\n\n");

    // 上半部分（包括中间）
    for (i = 0; i < n; i++) {
        // 打印空格
        for (j = 0; j < i; j++) {
            printf(" ");
        }

        // 打印星号
        for (j = 0; j < 2 * (n - i) - 1; j++) {
            printf("*");
        }

        printf("\n");
    }

    // 下半部分
    for (i = n - 2; i >= 0; i--) {
        // 打印空格
        for (j = 0; j < i; j++) {
            printf(" ");
        }

        // 打印星号
        for (j = 0; j < 2 * (n - i) - 1; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
