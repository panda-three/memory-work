#include <stdio.h>

/*
 * 穷举法题目7：三位数的水仙花数
 */
int main() {
    int num, a, b, c;
    int count = 0;

    printf("100-999之间的水仙花数：\n");

    for (num = 100; num <= 999; num++) {
        // 分解各位数字
        a = num / 100;
        b = (num / 10) % 10;
        c = num % 10;

        // 判断是否为水仙花数
        if (a*a*a + b*b*b + c*c*c == num) {
            printf("%d = %d³ + %d³ + %d³\n", num, a, b, c);
            count++;
        }
    }

    printf("\n共有 %d 个水仙花数\n", count);

    return 0;
}
