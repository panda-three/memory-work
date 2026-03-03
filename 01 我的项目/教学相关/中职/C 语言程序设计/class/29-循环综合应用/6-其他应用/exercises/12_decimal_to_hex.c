#include <stdio.h>

/*
 * 进制转换-题目12：十进制转十六进制
 */
int main() {
    int num, temp;
    char hex[32];
    int i = 0, j;

    printf("请输入一个十进制数: ");
    scanf("%d", &num);

    temp = num;

    // 除16取余法
    while (temp > 0) {
        int remainder = temp % 16;

        if (remainder < 10) {
            hex[i] = '0' + remainder;  // 0-9
        } else {
            hex[i] = 'A' + (remainder - 10);  // A-F
        }

        temp /= 16;
        i++;
    }

    printf("%d 的十六进制表示: 0x", num);

    // 逆序输出
    for (j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");

    return 0;
}
