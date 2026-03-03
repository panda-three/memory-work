#include <stdio.h>

/*
 * 穷举法题目9：鸡兔同笼
 */
int main() {
    int x, y;  // 鸡和兔的数量

    printf("鸡兔同笼问题：\n");
    printf("从上面数有35个头，从下面数有94只脚\n");
    printf("问鸡和兔各有多少只？\n\n");

    for (x = 0; x <= 35; x++) {
        y = 35 - x;  // 兔的数量

        // 检查脚数是否匹配
        if (2 * x + 4 * y == 94) {
            printf("鸡有 %d 只，兔有 %d 只\n", x, y);
            printf("\n验证：\n");
            printf("头数：%d + %d = %d ✓\n", x, y, x + y);
            printf("脚数：%d×2 + %d×4 = %d ✓\n", x, y, 2*x + 4*y);
            break;
        }
    }

    return 0;
}
