#include <stdio.h>

/*
 * 穷举法题目11：完全平方数
 */
int main() {
    int i;
    int count = 0;

    printf("1000以内的完全平方数：\n\n");

    // 方法1：直接计算 i²
    for (i = 1; i * i < 1000; i++) {
        printf("%4d ", i * i);
        count++;

        if (count % 10 == 0) {
            printf("\n");
        }
    }

    printf("\n\n共有 %d 个完全平方数\n", count);

    printf("\n公式：1² = 1, 2² = 4, 3² = 9, ..., 31² = 961\n");

    return 0;
}
