#include <stdio.h>

/*
 * 题目6：质因数分解
 */
int main() {
    int num, temp;
    int i;

    printf("请输入一个正整数: ");
    scanf("%d", &num);

    printf("%d = ", num);
    temp = num;

    // 从2开始试除
    for (i = 2; i <= temp; i++) {
        while (temp % i == 0) {
            printf("%d", i);
            temp /= i;

            if (temp > 1) {
                printf(" × ");
            }
        }

        if (temp == 1) break;
    }

    printf("\n");

    return 0;
}
