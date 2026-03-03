#include <stdio.h>

/*
 * 题目4：打印杨辉三角（前6行）
 */
int main() {
    int arr[10][10] = {0};  // 用于存储杨辉三角的数组
    int n = 6;  // 打印前6行
    int i, j;

    printf("杨辉三角（前%d行）:\n\n", n);

    // 生成杨辉三角
    for (i = 0; i < n; i++) {
        arr[i][0] = 1;  // 每行第一个数是1

        for (j = 1; j <= i; j++) {
            if (j == i) {
                arr[i][j] = 1;  // 每行最后一个数是1
            } else {
                // 其他数 = 上一行左上方 + 上一行正上方
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }

    // 打印杨辉三角
    for (i = 0; i < n; i++) {
        // 打印前导空格（美化）
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        // 打印这一行的数字
        for (j = 0; j <= i; j++) {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }

    return 0;
}
