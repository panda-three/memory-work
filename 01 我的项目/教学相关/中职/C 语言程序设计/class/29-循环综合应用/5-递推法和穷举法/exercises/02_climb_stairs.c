#include <stdio.h>

/*
 * 递推法题目2：爬楼梯问题
 */
int main() {
    int n;
    int i;
    int f1 = 1, f2 = 2, f;

    printf("请输入楼梯级数: ");
    scanf("%d", &n);

    if (n == 1) {
        printf("有 1 种爬法\n");
    } else if (n == 2) {
        printf("有 2 种爬法\n");
    } else {
        // f(n) = f(n-1) + f(n-2)
        for (i = 3; i <= n; i++) {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
        }
        printf("有 %d 种爬法\n", f);
    }

    printf("\n解释：\n");
    printf("f(1) = 1  (只能1步)\n");
    printf("f(2) = 2  (1+1 或 2)\n");
    printf("f(3) = 3  (1+1+1 或 1+2 或 2+1)\n");
    printf("规律：f(n) = f(n-1) + f(n-2)\n");

    return 0;
}
