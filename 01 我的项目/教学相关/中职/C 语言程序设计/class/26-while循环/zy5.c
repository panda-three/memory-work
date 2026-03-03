/* 判断一个整数是否为回文数 */
#include <stdio.h>

int main(void)
{
    int x;
    printf("请输入一个整数：");
    if (scanf("%d", &x) != 1) return 0;

    if (x < 0) {
        printf("no\n");
        return 0;
    }

    int original = x;
    int reversed = 0;
    while (x != 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    printf("%s\n", original == reversed ? "yes" : "no");
    return 0;
}
