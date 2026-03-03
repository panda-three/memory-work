#include <stdio.h>

/*
 * 数字处理类-题目3：统计数字中各个数字出现的次数
 */
int main() {
    long long num;
    int count[10] = {0};  // 存储0-9每个数字的出现次数
    int digit;
    int i;

    printf("请输入一个整数: ");
    scanf("%lld", &num);

    // 统计每个数字出现的次数
    while (num > 0) {
        digit = num % 10;
        count[digit]++;
        num /= 10;
    }

    printf("\n数字出现统计：\n");
    for (i = 0; i <= 9; i++) {
        if (count[i] > 0) {
            printf("%d 出现 %d 次\n", i, count[i]);
        }
    }

    return 0;
}
