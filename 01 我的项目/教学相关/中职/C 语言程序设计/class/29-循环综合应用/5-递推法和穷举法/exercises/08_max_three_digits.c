#include <stdio.h>

/*
 * 穷举法题目8：三个数字组成最大数
 */
int main() {
    int a, b, c;
    int num1, num2, num3, num4, num5, num6;
    int max;

    printf("请输入三个数字: ");
    scanf("%d %d %d", &a, &b, &c);

    // 穷举所有可能的组合
    num1 = a * 100 + b * 10 + c;  // abc
    num2 = a * 100 + c * 10 + b;  // acb
    num3 = b * 100 + a * 10 + c;  // bac
    num4 = b * 100 + c * 10 + a;  // bca
    num5 = c * 100 + a * 10 + b;  // cab
    num6 = c * 100 + b * 10 + a;  // cba

    // 找出最大值
    max = num1;
    if (num2 > max) max = num2;
    if (num3 > max) max = num3;
    if (num4 > max) max = num4;
    if (num5 > max) max = num5;
    if (num6 > max) max = num6;

    printf("\n所有可能的组合：\n");
    printf("%d %d %d %d %d %d\n", num1, num2, num3, num4, num5, num6);
    printf("\n最大的数是：%d\n", max);

    return 0;
}
