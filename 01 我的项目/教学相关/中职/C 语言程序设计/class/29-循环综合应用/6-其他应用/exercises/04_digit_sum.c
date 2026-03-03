#include <stdio.h>

/*
 * 数字处理类-题目4：数字各位之和
 */
int main() {
    int num, sum = 0;
    int temp;

    printf("请输入一个整数: ");
    scanf("%d", &num);

    temp = num;

    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }

    printf("%d 的各位数字之和 = %d\n", num, sum);

    return 0;
}
