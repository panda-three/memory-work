#include <stdio.h>

/*
 * 综合应用-题目22：数列求和
 * 1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ... + 1/99 - 1/100
 */
int main() {
    double sum = 0.0;
    int i;
    int sign = 1;  // 符号

    for (i = 1; i <= 100; i++) {
        sum += sign * (1.0 / i);
        sign = -sign;  // 符号翻转
    }

    printf("1 - 1/2 + 1/3 - 1/4 + ... + 1/99 - 1/100\n\n");
    printf("和 = %.6f\n", sum);

    return 0;
}
