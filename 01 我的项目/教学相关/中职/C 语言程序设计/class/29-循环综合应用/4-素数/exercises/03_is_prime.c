#include <stdio.h>

/*
 * 题目1：判断一个数是否为质数
 */
int main() {
    int num;
    int isPrime = 1;  // 假设是质数
    int i;

    printf("请输入一个正整数: ");
    scanf("%d", &num);

    if (num < 2) {
        isPrime = 0;  // 小于2的数不是质数
    } else {
        // 从2判断到sqrt(num)
        for (i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0;  // 能被整除,不是质数
                break;
            }
        }
    }

    if (isPrime) {
        printf("%d 是质数\n", num);
    } else {
        printf("%d 不是质数\n", num);
    }

    return 0;
}
