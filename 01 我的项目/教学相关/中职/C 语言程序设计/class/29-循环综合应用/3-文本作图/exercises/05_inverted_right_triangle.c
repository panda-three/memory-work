#include <stdio.h>

/*
 * 题目6：打印倒直角三角形（右对齐）
 */
int main() {
    int n = 5;
    int i, j;

    printf("倒直角三角形（右对齐）:\n\n");

    for (i = 1; i <= n; i++) {
        // 打印空格（递增）
        for (j = 1; j < i; j++) {
            printf(" ");
        }

        // 打印星号（递减）
        for (j = 1; j <= n - i + 1; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
