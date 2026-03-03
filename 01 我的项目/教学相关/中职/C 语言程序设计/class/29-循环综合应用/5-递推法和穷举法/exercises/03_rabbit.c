#include <stdio.h>

/*
 * 递推法题目3：兔子繁殖问题
 */
int main() {
    int n;
    int month1 = 1, month2 = 1, current;
    int i;

    printf("请输入月数: ");
    scanf("%d", &n);

    if (n <= 2) {
        printf("%d个月后有 1 对兔子\n", n);
    } else {
        for (i = 3; i <= n; i++) {
            current = month1 + month2;
            month1 = month2;
            month2 = current;
        }
        printf("%d个月后有 %d 对兔子\n", n, current);
    }

    printf("\n说明：\n");
    printf("第1个月：1对（新生）\n");
    printf("第2个月：1对（未成熟）\n");
    printf("第3个月：2对（第1对生了1对）\n");
    printf("第4个月：3对\n");
    printf("第5个月：5对\n");
    printf("...\n");

    return 0;
}
