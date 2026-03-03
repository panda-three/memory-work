#include <stdio.h>

/*
 * 统计计数-题目18：连续数字统计
 */
int main() {
    long long num;
    int prev = -1, current;
    int maxCount = 0, currentCount = 0;
    int maxDigit = -1;

    printf("请输入一个整数: ");
    scanf("%lld", &num);

    long long original = num;

    // 从右到左处理每一位
    while (num > 0) {
        current = num % 10;

        if (current == prev) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                maxDigit = prev;
            }
            currentCount = 1;
        }

        prev = current;
        num /= 10;
    }

    // 检查最后一组
    if (currentCount > maxCount) {
        maxCount = currentCount;
        maxDigit = prev;
    }

    printf("\n在 %lld 中，数字 %d 连续出现 %d 次最多\n",
           original, maxDigit, maxCount);

    return 0;
}
