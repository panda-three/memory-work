#include <stdio.h>

/*
 * 题目10：质数间隔
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
    int i;
    int prevPrime = 2;   // 前一个质数
    int maxGap = 0;      // 最大间隔
    int prime1, prime2;  // 间隔最大的两个质数

    for (i = 3; i <= 100; i++) {
        if (isPrime(i)) {
            int gap = i - prevPrime;  // 当前间隔

            if (gap > maxGap) {
                maxGap = gap;
                prime1 = prevPrime;
                prime2 = i;
            }

            prevPrime = i;  // 更新前一个质数
        }
    }

    printf("100以内相邻质数间隔最大的一对是：\n");
    printf("%d 和 %d，间隔为 %d\n", prime1, prime2, maxGap);

    return 0;
}
