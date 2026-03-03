#include <stdio.h>

/*
 * 题目4：寻找区间内的孪生质数
 */

// 判断一个数是否为质数的函数
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
    int count = 0;

    printf("100以内的孪生质数对：\n");

    for (i = 2; i <= 98; i++) {
        if (isPrime(i) && isPrime(i + 2)) {
            printf("(%d, %d)  ", i, i + 2);
            count++;

            if (count % 5 == 0) {  // 每5对换行
                printf("\n");
            }
        }
    }

    printf("\n\n共找到 %d 对孪生质数\n", count);

    return 0;
}
