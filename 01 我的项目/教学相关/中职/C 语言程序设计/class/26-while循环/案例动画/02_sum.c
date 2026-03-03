/*
 * 练习2：求和
 * 要求：求1-5之间的和
 *
 * 知识点：while循环中的累加操作
 */

#include <stdio.h>

int main() {
    printf("=== 求1-5之间的和 ===\n\n");

    int sum = 0;  // 累加和
    int i = 1;    // 循环变量

    // 使用while循环累加1-5
    while (i <= 5) {
        sum = sum + i;  // 或者写成 sum += i;
        printf("i=%d, sum=%d\n", i, sum);
        i++;
    }

    printf("\n最终结果：1+2+3+4+5 = %d\n", sum);

    return 0;
}

/*
 * 运行结果：
 * === 求1-5之间的和 ===
 *
 * i=1, sum=1
 * i=2, sum=3
 * i=3, sum=6
 * i=4, sum=10
 * i=5, sum=15
 *
 * 最终结果：1+2+3+4+5 = 15
 *
 * 知识点总结：
 * 1. 累加变量sum需要初始化为0
 * 2. 每次循环将当前值加到sum上
 * 3. 循环结束后sum保存最终结果
 * 4. 可以在循环中打印中间过程，帮助理解
 */
