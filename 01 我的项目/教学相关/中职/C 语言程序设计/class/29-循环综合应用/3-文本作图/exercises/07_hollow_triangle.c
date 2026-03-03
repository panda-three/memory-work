#include <stdio.h>

/*
 * 题目8：打印空心等腰三角形
 */
int main() {
    int n = 5;
    int i, j;

    printf("空心等腰三角形:\n\n");

    for (i = 1; i <= n; i++) {
        // 打印前导空格
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // 打印星号部分
        for (j = 1; j <= 2 * i - 1; j++) {
            // 最后一行全打印，其他行只打印两端
            if (i == n || j == 1 || j == 2 * i - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
