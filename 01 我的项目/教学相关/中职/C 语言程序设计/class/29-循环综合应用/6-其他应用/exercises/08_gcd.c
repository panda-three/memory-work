#include <stdio.h>

/*
 * 最值问题-题目8：最大公约数（辗转相除法）
 */
int main() {
    int a, b;
    int temp;

    printf("请输入两个正整数: ");
    scanf("%d %d", &a, &b);

    int original_a = a, original_b = b;

    // 辗转相除法
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }

    printf("%d 和 %d 的最大公约数是: %d\n", original_a, original_b, a);

    return 0;
}
