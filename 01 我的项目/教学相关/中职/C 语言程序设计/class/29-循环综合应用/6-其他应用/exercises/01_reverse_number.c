#include <stdio.h>

/*
 * 数字处理类-题目1：数字反转
 */
int main() {
    int num, reversed = 0;
    int temp;

    printf("请输入一个整数: ");
    scanf("%d", &num);

    temp = num;

    while (temp > 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }

    printf("原数：%d\n", num);
    printf("反转后：%d\n", reversed);

    return 0;
}
