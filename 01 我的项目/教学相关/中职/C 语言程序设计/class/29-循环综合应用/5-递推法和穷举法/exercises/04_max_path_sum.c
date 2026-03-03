#include <stdio.h>

/*
 * 递推法题目4：数字三角形路径和（简化版）
 */
int main() {
    // 定义三角形
    int triangle[4][4] = {
        {7, 0, 0, 0},
        {3, 8, 0, 0},
        {8, 1, 0, 0},
        {2, 7, 4, 4}
    };

    int dp[4][4];  // 存储到每个位置的最大路径和
    int i, j;

    // 初始化底部
    for (i = 0; i < 4; i++) {
        dp[3][i] = triangle[3][i];
    }

    // 从下往上递推
    for (i = 2; i >= 0; i--) {
        for (j = 0; j <= i; j++) {
            // 选择下一行相邻两个位置中较大的
            if (dp[i+1][j] > dp[i+1][j+1]) {
                dp[i][j] = triangle[i][j] + dp[i+1][j];
            } else {
                dp[i][j] = triangle[i][j] + dp[i+1][j+1];
            }
        }
    }

    printf("数字三角形：\n");
    printf("   7\n");
    printf("  3 8\n");
    printf(" 8 1 0\n");
    printf("2 7 4 4\n\n");

    printf("最大路径和 = %d\n", dp[0][0]);

    return 0;
}
