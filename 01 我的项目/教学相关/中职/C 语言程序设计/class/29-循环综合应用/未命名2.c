#include <stdio.h>
int main() {
    int num, temp;
    int binary[32];
    int i = 0, j;

    printf("请输入一个十进制数: ");
    scanf("%d", &num);

    temp = num;
    int y=0; 

    // 除2取余法
    while (temp > 0) {
        int wei= temp % 2;
        y
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

