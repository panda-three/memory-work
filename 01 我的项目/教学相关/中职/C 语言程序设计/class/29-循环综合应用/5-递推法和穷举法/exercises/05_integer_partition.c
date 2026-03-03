#include <stdio.h>

/*
 * 递推法题目5：整数拆分（简化版）
 * 对于给定的n，找出使乘积最大的拆分方案
 */
int main() {
    int n;
    int i, j;
    int max = 0;

    printf("请输入正整数n: ");
    scanf("%d", &n);

    printf("\n%d 的部分拆分方案：\n", n);

    // 尝试不同的拆分方式
    // 拆成2个数
    for (i = 1; i < n; i++) {
        int product = i * (n - i);
        if (product > max) {
            max = product;
        }
        printf("%d = %d + %d, 乘积 = %d\n", n, i, n-i, product);
    }

    // 拆成3个数（只展示几种）
    printf("\n拆成3个数的情况（部分）：\n");
    for (i = 1; i < n-1; i++) {
        for (j = 1; j < n-i; j++) {
            int k = n - i - j;
            if (k > 0) {
                int product = i * j * k;
                if (product > max) {
                    max = product;
                }

                if (i <= 3 && j <= 3) {  // 只展示部分
                    printf("%d = %d + %d + %d, 乘积 = %d\n",
                           n, i, j, k, product);
                }
            }
        }
    }

    printf("\n最大乘积 = %d\n", max);

    return 0;
}
