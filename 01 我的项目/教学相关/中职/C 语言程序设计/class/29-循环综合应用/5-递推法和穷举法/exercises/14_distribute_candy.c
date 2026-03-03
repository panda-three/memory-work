#include <stdio.h>

/*
 * 穷举法题目14：分糖果问题
 */
int main() {
    int x, y, z;
    int count = 0;

    printf("10颗糖果分给3个小朋友，每人至少1颗\n");
    printf("所有分法：\n\n");
    printf("甲\t乙\t丙\n");
    printf("-------------------\n");

    for (x = 1; x <= 8; x++) {
        for (y = 1; y <= 8; y++) {
            z = 10 - x - y;

            if (z >= 1) {
                printf("%d\t%d\t%d\n", x, y, z);
                count++;
            }
        }
    }

    printf("\n共有 %d 种分法\n", count);

    return 0;
}
