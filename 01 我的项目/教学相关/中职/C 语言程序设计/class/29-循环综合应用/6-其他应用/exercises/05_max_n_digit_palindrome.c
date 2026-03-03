#include <stdio.h>

/*
 * 数字处理类-题目5：找出n位最大回文数
 */
int main() {
    int n, i;
    int max, start;

    printf("请输入位数n: ");
    scanf("%d", &n);

    // n位数的最大值
    max = 1;
    for (i = 0; i < n; i++) {
        max *= 10;
    }
    max -= 1;  // 例如：3位数最大是999

    // 从最大值开始向下找
    for (i = max; i >= max / 10; i--) {
        int original = i;
        int reversed = 0;
        int temp = i;

        // 反转数字
        while (temp > 0) {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }

        if (original == reversed) {
            printf("%d位最大回文数是: %d\n", n, i);
            return 0;
        }
    }

    return 0;
}
