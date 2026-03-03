#include <stdio.h>

/*
 * 统计计数-题目16：阶乘中末尾0的个数
 */
int main() {
    int n;
    int count = 0;
    int i;

    printf("请输入n，计算n!末尾0的个数: ");
    scanf("%d", &n);

    // 统计5的个数（每个5贡献一个0）
    for (i = 5; i <= n; i *= 5) {
        count += n / i;
    }

    printf("%d! 末尾有 %d 个0\n", n, count);

    printf("\n解释：\n");
    printf("末尾的0由2×5产生，而2的个数总是多于5\n");
    printf("所以只需统计5的个数即可\n");

    return 0;
}
