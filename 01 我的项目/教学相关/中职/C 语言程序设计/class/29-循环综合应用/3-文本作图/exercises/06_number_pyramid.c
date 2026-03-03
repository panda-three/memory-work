#include <stdio.h>

/*
 * 题目7：打印数字金字塔
 */
int main() {
    int n = 5;
    int i, j;

    printf("数字金字塔:\n\n");

    for (i = 1; i <= n; i++) {
        // 打印前导空格
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // 打印递增数字
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // 打印递减数字
        for (j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        printf("\n");
    }

    return 0;
}
