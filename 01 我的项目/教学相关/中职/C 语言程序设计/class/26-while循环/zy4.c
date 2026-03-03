/* 计算非负整数 x 的算术平方根（只保留整数部分） */
#include <stdio.h>

int main(void)
{
    int x;
    printf("请输入一个非负整数 x：");
    if (scanf("%d", &x) != 1 || x < 0) return 0;

    int res = 0;
    while ((long long)(res + 1) * (res + 1) <= x) ++res;
    printf("整数平方根：%d\n", res);
    return 0;
}
