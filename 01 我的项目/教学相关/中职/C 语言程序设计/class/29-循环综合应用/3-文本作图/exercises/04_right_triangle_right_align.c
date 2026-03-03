#include <stdio.h>

/*
 * 题目5：打印直角三角形（右对齐）
 */
int main() {
    int n = 5;
    int i, j;

    printf("直角三角形（右对齐）:\n\n");

    for (i = 1; i <= n; i++) {
        // 打印空格（递减）
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // 打印星号（递增）
        for (j = 1; j <= i; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
