#include <stdio.h>

/*
 * 打印矩形(带详细调试信息)
 * 目标:让学生理解"外循环控制行,内循环控制列"
 */
int main() {
    int rows = 4;  // 4行
    int cols = 6;  // 6列

    printf("=== 打印%d行%d列的矩形 ===\n\n", rows, cols);

    // 外循环:控制行数
     int i,j; 
    for (i = 1; i <= rows; i++) {
        printf("[第%d行]", i);  // 显示当前行号

        // 内循环:控制每行的列数
        for (j = 1; j <= cols; j++) {
            printf(" *");
        }
        printf("\n");  // 一行打印完后换行
    }

    printf("\n总结:\n");
    printf("- 外循环执行%d次 → 打印%d行\n", rows, rows);
    printf("- 内循环每次执行%d次 → 每行打印%d个星号\n", cols, cols);
    printf("- 总共打印了 %d × %d = %d 个星号\n", rows, cols, rows * cols);

    return 0;
}
