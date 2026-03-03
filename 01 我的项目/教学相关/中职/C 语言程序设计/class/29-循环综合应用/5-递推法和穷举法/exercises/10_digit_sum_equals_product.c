#include <stdio.h>

/*
 * 穷举法题目10：找出四位数中各位数字之和等于各位数字之积的数
 */
int main() {
    int num, a, b, c, d;
    int sum, product;
    int count = 0;

    printf("1000-9999中各位数字之和等于各位数字之积的数：\n\n");

    for (num = 1000; num <= 9999; num++) {
        // 分解各位数字
        a = num / 1000;
        b = (num / 100) % 10;
        c = (num / 10) % 10;
        d = num % 10;

        sum = a + b + c + d;
        product = a * b * c * d;

        if (sum == product && product != 0) {  // 排除乘积为0的情况
            printf("%d: %d+%d+%d+%d = %d, %d×%d×%d×%d = %d\n",
                   num, a, b, c, d, sum, a, b, c, d, product);
            count++;
        }
    }

    if (count == 0) {
        printf("没有找到符合条件的四位数\n");
        printf("\n说明：这个条件非常严格，四位数中可能不存在这样的数\n");
    } else {
        printf("\n共找到 %d 个符合条件的数\n", count);
    }

    return 0;
}
