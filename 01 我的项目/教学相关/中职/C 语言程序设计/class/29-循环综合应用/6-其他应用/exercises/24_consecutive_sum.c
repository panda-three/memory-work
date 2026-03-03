#include <stdio.h>

/*
 * 综合应用-题目25：数字拆分求和
 */
int main() {
    int num;
    int start, end, sum;
    int count = 0;

    printf("请输入一个正整数: ");
    scanf("%d", &num);

    printf("\n%d 可以表示为以下连续自然数之和：\n\n", num);

    // 枚举起始位置
    for (start = 1; start < num; start++) {
        sum = 0;

        // 从start开始累加
        for (end = start; sum < num; end++) {
            sum += end;

            if (sum == num) {
                // 找到一组解
                printf("%d = ", num);

                int i;
                for (i = start; i <= end; i++) {
                    printf("%d", i);
                    if (i < end) {
                        printf(" + ");
                    }
                }
                printf("\n");

                count++;
                break;
            }
        }
    }

    if (count == 0) {
        printf("没有找到符合条件的拆分\n");
    } else {
        printf("\n共有 %d 种拆分方式\n", count);
    }

    return 0;
}
