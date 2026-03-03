#include <stdio.h>

/*
 * 穷举法题目6：百钱买百鸡（经典题）
 */
int main() {
    int x, y, z;  // 公鸡、母鸡、小鸡的数量
    int count = 0;

    printf("百钱买百鸡问题：\n");
    printf("公鸡5元一只，母鸡3元一只，小鸡1元3只\n");
    printf("用100元买100只鸡，求各有多少只？\n\n");

    printf("所有可能的方案：\n");
    printf("公鸡\t母鸡\t小鸡\n");
    printf("------------------------\n");

    for (x = 0; x <= 20; x++) {  // 公鸡最多20只（100/5）
        for (y = 0; y <= 33; y++) {  // 母鸡最多33只（100/3）
            z = 100 - x - y;  // 小鸡数量

            // 检查是否满足价格条件
            if (z >= 0 && z % 3 == 0 && 5*x + 3*y + z/3 == 100) {
                printf("%d\t%d\t%d\n", x, y, z);
                count++;
            }
        }
    }

    printf("\n共有 %d 种方案\n", count);

    return 0;
}
