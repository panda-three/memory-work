#include <stdio.h>

/*
 * 进制转换-题目10：十进制转二进制
 */
int main() {
    int num, temp;
    int binary[32];
    int i = 0, j;

    printf("请输入一个十进制数: ");
    scanf("%d", &num);

    temp = num;

    // 除2取余法
    while (temp > 0) {
        binary[i] = temp % 2;
        temp /= 2;
        i++;
    }

    printf("%d 的二进制表示: ", num);

    // 逆序输出
    for (j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");

    return 0;
}
