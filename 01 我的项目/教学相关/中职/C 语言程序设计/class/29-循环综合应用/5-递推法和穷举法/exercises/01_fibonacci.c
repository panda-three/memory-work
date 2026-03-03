#include <stdio.h>

/*
 * 递推法题目1：斐波那契数列
 */
int main() {
    int a = 1, b = 1, c;
    int i;

    printf("斐波那契数列前20项：\n");
    printf("%d %d ", a, b);

    for (i = 3; i <= 20; i++) {
        c = a + b;
        printf("%d ", c);

        // 更新ab的值
        a = b;
        b = c;

        if (i % 10 == 0) {
            printf("\n");
        }
    }

    printf("\n");

    return 0;
}
