#include <stdio.h>

/*
 * 题目3：统计并输出100-200之间的质数个数
 */
int main() {
    int count = 0;
    int i, j;

    for (i = 100; i <= 200; i++) {
        int isPrime = 1;

        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            count++;
        }
    }

    printf("100-200之间共有 %d 个质数\n", count);

    return 0;
}
