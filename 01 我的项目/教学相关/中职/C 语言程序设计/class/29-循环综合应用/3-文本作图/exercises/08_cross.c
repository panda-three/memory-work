#include <stdio.h>

/*
 * 题目9：打印十字架图案
 */
int main() {
    int n = 7;  // 7行7列
    int i, j;
    int mid = (n + 1) / 2;  // 中间位置

    printf("十字架图案 (%d x %d):\n\n", n, n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            // 在中间行或中间列打印星号
            if (i == mid || j == mid) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
