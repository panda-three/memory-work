#include <stdio.h>

/*
 * 特殊数字-题目13：完全数
 */
int main() {
    int num, i;
    int sum;
    int count = 0;

    printf("1000以内的完全数：\n\n");

    for (num = 2; num <= 1000; num++) {
        sum = 0;

        // 找出num的所有真因子并求和
        for (i = 1; i < num; i++) {
            if (num % i == 0) {
                sum += i;
            }
        }

        // 如果真因子之和等于该数本身
        if (sum == num) {
            printf("%d = ", num);

            // 输出真因子
            int first = 1;
            for (i = 1; i < num; i++) {
                if (num % i == 0) {
                    if (!first) printf(" + ");
                    printf("%d", i);
                    first = 0;
                }
            }
            printf("\n");
            count++;
        }
    }

    printf("\n共找到 %d 个完全数\n", count);

    return 0;
}
