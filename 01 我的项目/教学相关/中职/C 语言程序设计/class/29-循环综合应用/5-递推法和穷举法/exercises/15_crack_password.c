#include <stdio.h>

/*
 * 穷举法题目15：破解三位数密码
 */
int main() {
    int a, b, c;
    int num;
    int count = 0;

    printf("密码规则：\n");
    printf("1. 三个数字各不相同\n");
    printf("2. 百位数字是个位数字的2倍\n");
    printf("3. 三个数字之和是15\n\n");

    printf("所有可能的密码：\n");

    for (a = 1; a <= 9; a++) {  // 百位（不能为0）
        for (b = 0; b <= 9; b++) {  // 十位
            for (c = 0; c <= 9; c++) {  // 个位
                // 检查所有条件
                if (a != b && b != c && a != c &&  // 各不相同
                    a == 2 * c &&                   // 百位是个位的2倍
                    a + b + c == 15) {              // 和为15

                    num = a * 100 + b * 10 + c;
                    printf("%d (百位=%d, 十位=%d, 个位=%d)\n", num, a, b, c);
                    count++;
                }
            }
        }
    }

    printf("\n共有 %d 个可能的密码\n", count);

    return 0;
}
