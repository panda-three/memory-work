#include <stdio.h>

/*
 * 穷举法题目13：数字组合问题
 */
int main() {
    int i, j, k;
    int count = 0;

    printf("用1,2,3,4四个数字组成的三位数（无重复数字）：\n\n");

    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 4; j++) {
            for (k = 1; k <= 4; k++) {
                // 确保三个数字互不相同
                if (i != j && j != k && i != k) {
                    printf("%d%d%d ", i, j, k);
                    count++;

                    if (count % 10 == 0) {
                        printf("\n");
                    }
                }
            }
        }
    }

    printf("\n\n共能组成 %d 个不同的三位数\n", count);
    printf("计算公式：P(4,3) = 4×3×2 = 24\n");

    return 0;
}
