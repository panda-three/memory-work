#include <stdio.h>

/*
 * 最值问题-题目9：最小公倍数
 */
int main() {
    int a, b;
    int gcd, lcm;
    int temp;

    printf("请输入两个正整数: ");
    scanf("%d %d", &a, &b);

    int original_a = a, original_b = b;

    // 先求最大公约数
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    gcd = a;

    // 最小公倍数 = 两数之积 / 最大公约数
    lcm = (original_a * original_b) / gcd;

    printf("%d 和 %d 的最小公倍数是: %d\n", original_a, original_b, lcm);

    return 0;
}
