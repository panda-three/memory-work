#include <stdio.h>

/*
 * 题目5：哥德巴赫猜想验证
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
    int num;
    int i;
    int count = 0;

    printf("请输入一个大于2的偶数: ");
    scanf("%d", &num);

    if (num <= 2 || num % 2 != 0) {
        printf("输入错误！必须是大于2的偶数\n");
        return 1;
    }

    printf("\n%d 可以表示为以下质数对之和：\n", num);

    for (i = 2; i <= num / 2; i++) {
        if (isPrime(i) && isPrime(num - i)) {
            printf("%d = %d + %d\n", num, i, num - i);
            count++;
        }
    }

    printf("\n共找到 %d 种表示方法\n", count);

    return 0;
}
