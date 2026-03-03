/* 判断一个整数是否是 2 的幂次方 */
#include <stdio.h>

int main(void)
{
    int n;
    printf("请输入一个整数 n：");
    if (scanf("%d", &n) != 1) return 0;

    if (n <= 0) {
        printf("no\n");
        return 0;
    }

    while (n % 2 == 0) n /= 2;
    printf("%s\n", n == 1 ? "yes" : "no");
    return 0;
}
