#include <stdio.h>

/*
 * 统计计数-题目17：数字频率统计
 */
int main() {
    long long num;
    int count[10] = {0};
    int i, j;

    printf("请输入一个整数: ");
    scanf("%lld", &num);

    // 统计每个数字出现的次数
    long long temp = num;
    while (temp > 0) {
        count[temp % 10]++;
        temp /= 10;
    }

    printf("\n数字频率统计（从高到低）：\n");

    // 找出最大频率
    int maxFreq = 0;
    for (i = 0; i <= 9; i++) {
        if (count[i] > maxFreq) {
            maxFreq = count[i];
        }
    }

    // 按频率从高到低输出
    for (i = maxFreq; i >= 1; i--) {
        for (j = 0; j <= 9; j++) {
            if (count[j] == i) {
                printf("数字 %d 出现 %d 次\n", j, count[j]);
            }
        }
    }

    return 0;
}
