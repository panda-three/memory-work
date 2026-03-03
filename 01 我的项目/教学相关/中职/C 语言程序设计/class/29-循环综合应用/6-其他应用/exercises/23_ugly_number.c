#include <stdio.h>

/*
 * 综合应用-题目24：丑数
 */

// 判断是否为丑数
int isUgly(int n) {
    if (n <= 0) return 0;

    // 不断除以2, 3, 5
    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;

    return n == 1;  // 如果最后等于1，说明只包含2,3,5这些因子
}

int main() {
    int n;
    int count = 0;
    int num = 1;

    printf("请输入n，找出第n个丑数: ");
    scanf("%d", &n);

    printf("\n前%d个丑数：\n", n);

    while (count < n) {
        if (isUgly(num)) {
            printf("%d ", num);
            count++;

            if (count % 10 == 0) {
                printf("\n");
            }
        }
        num++;
    }

    printf("\n\n第%d个丑数是: %d\n", n, num - 1);

    return 0;
}
