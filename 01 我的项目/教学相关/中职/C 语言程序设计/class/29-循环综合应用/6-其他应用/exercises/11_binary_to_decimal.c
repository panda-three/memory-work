#include <stdio.h>

/*
 * 进制转换-题目11：二进制转十进制
 */
int main() {
    long long binary;
    int decimal = 0;
    int base = 1;
    int digit;

    printf("请输入一个二进制数: ");
    scanf("%lld", &binary);

    long long original = binary;

    // 从右到左处理每一位
    // 1011  ==  1*2^0 + 1*2^1 + 0*2^2 + 1*2^3 = 1 + 2 + 0 + 8 = 11
    while (binary > 0) {
        digit = binary % 10;
        decimal += digit * base;
        base *= 2;
        binary /= 10;
    }

    printf("二进制 %lld 的十进制表示: %d\n", original, decimal);

    return 0;
}
