/* 反转一个整数 */
#include <stdio.h>

int main(void)
{
    int x;
    printf("请输入一个整数：");
    if (scanf("%d", &x) != 1) return 0;

    int reversed = 0;
    while (x != 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    printf("反转后：%d\n", reversed);
    return 0;
}
