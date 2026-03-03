#include <stdio.h>

/*
 * 题目9：找出n以内最大的质数
 */

// 判断质数
int isPrime(int n) {
    int i;
    if (n < 2) return 0;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    int i;

    printf("请输入n: ");
    scanf("%d", &n);

    // 从n开始向下找，找到的第一个质数就是最大的
    for (i = n; i >= 2; i--) {
        if (isPrime(i)) {
            printf("%d 以内最大的质数是: %d\n", n, i);
            break;
        }
    }

    return 0;
}
