#include <stdio.h>

/*
 * 特殊数字-题目14：亲密数
 */

// 计算一个数的所有真因子之和
int sumOfDivisors(int n) {
    int sum = 0;
    int i;

    for (i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    int i;
    int sum1, sum2;
    int count = 0;

    printf("1000以内的亲密数对：\n\n");

    for (i = 2; i < 1000; i++) {
        sum1 = sumOfDivisors(i);

        if (sum1 > i && sum1 < 1000) {  // 避免重复和超范围
            sum2 = sumOfDivisors(sum1);

            if (sum2 == i) {
                printf("(%d, %d)\n", i, sum1);
                count++;
            }
        }
    }

    printf("\n共找到 %d 对亲密数\n", count);

    return 0;
}
