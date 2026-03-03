/*
 * 练习5：整数反转
 * 将一个整数X，进行反转
 * 举例：123 反转之后变成321
 *
 * 知识点：while循环、数字拆分和重组
 */

#include <stdio.h>

int main() {
    printf("=== 整数反转 ===\n\n");

    int num = 123;
    int reversed = 0;  // 存储反转后的数字

    printf("原始数字：%d\n\n", num);
    printf("反转过程：\n");

    int temp = num;  // 使用临时变量，保留原始值
    while (temp > 0) {
        int digit = temp % 10;              // 取出最后一位数字
        reversed = reversed * 10 + digit;   // 将数字添加到反转数的末尾
        temp = temp / 10;                   // 去掉最后一位数字

        printf("取出数字: %d, 反转中: %d, 剩余: %d\n", digit, reversed, temp);
    }

    printf("\n反转结果：%d → %d\n", num, reversed);

    return 0;
}

/*
 * 运行结果：
 * === 整数反转 ===
 *
 * 原始数字：123
 *
 * 反转过程：
 * 取出数字: 3, 反转中: 3, 剩余: 12
 * 取出数字: 2, 反转中: 32, 剩余: 1
 * 取出数字: 1, 反转中: 321, 剩余: 0
 *
 * 反转结果：123 → 321
 *
 * 知识点总结：
 * 1. 取最后一位：digit = temp % 10
 * 2. 去掉最后一位：temp = temp / 10
 * 3. 构建反转数：reversed = reversed * 10 + digit
 *    - 第1次：0 * 10 + 3 = 3
 *    - 第2次：3 * 10 + 2 = 32
 *    - 第3次：32 * 10 + 1 = 321
 * 4. 循环条件：temp > 0（当所有位都处理完，temp变为0）
 * 5. 这是while循环的经典应用场景（循环次数不确定）
 */
