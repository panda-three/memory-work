#include <stdio.h>

/*
 * 数字处理类-题目2：回文数判断
 */
int main() {
    int num, original, reversed = 0;
    int temp;

    printf("请输入一个整数: ");
    scanf("%d", &num);

    original = num;
    temp = num;

    // 反转数字
    while (temp > 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }

    if (original == reversed) {
        printf("%d 是回文数\n", num);
    } else {
        printf("%d 不是回文数\n", num);
    }

    return 0;
}
