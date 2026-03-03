#include <stdio.h>

/*
 * 特殊数字-题目15：自守数
 */
int main() {
    int i;
    long long square;
    int count = 0;

    printf("100以内的自守数：\n\n");

    for (i = 0; i <= 100; i++) {
        square = (long long)i * i;

        // 检查平方的末尾是否等于该数
        if (i < 10) {
            if (square % 10 == i) {
                printf("%d: %d² = %lld\n", i, i, square);
                count++;
            }
        } else {
            if (square % 100 == i) {
                printf("%d: %d² = %lld\n", i, i, square);
                count++;
            }
        }
    }

    printf("\n共找到 %d 个自守数\n", count);

    return 0;
}
