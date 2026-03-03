#include <stdio.h>

/*
 * 题目8：回文质数
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

// 判断回文数
int isPalindrome(int n) {
    int original = n;
    int reversed = 0;

    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    return original == reversed;
}

int main() {
    int i;
    int count = 0;

    printf("100-999之间的回文质数：\n");

    for (i = 100; i <= 999; i++) {
        if (isPalindrome(i) && isPrime(i)) {
            printf("%d ", i);
            count++;
 
            if (count % 10 == 0) {
                printf("\n");
            }
        }
    }

    printf("\n\n共找到 %d 个回文质数\n", count);

    return 0;
}
