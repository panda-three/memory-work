#include <stdio.h>

/*
 * 题目1：打印6行10列的空心矩形（已有01_kongxin.c，这是补充版本）
 */
int main() {
    int rows = 6, cols = 10;
    int i, j;

    printf("空心矩形 (%d行%d列):\n\n", rows, cols);

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= cols; j++) {
            // 边界位置打印星号，否则打印空格
            if (i == 1 || i == rows || j == 1 || j == cols) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}
