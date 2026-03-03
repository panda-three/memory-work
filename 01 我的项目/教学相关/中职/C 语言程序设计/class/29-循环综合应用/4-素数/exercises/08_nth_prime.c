#include <stdio.h>

/*
 * 题目7：寻找第n个质数
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
    int count = 0;
    int num = 2;

    printf("请输入n，找出第n个质数: ");
    scanf("%d", &n);

    while (count < n) {
        if (isPrime(num)) {
            count++;
            if (count == n) {
                printf("第 %d 个质数是: %d\n", n, num);
                break;
            }
        }
        num++;
    }

    return 0;
}
