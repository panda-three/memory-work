#include <stdio.h>

/*
 * 九九乘法表 - 第二步:改成直角三角形
 * 关键:j <= i (不是j <= 9了!)
 */
int main() {
    printf("=== 第二步:改成直角三角形 ===\n\n");
    int i,j ; 
    for ( i = 1; i <= 9; i++) {
        for ( j = 1; j <= i; j++) {    // 【改这里】j <= i
            printf("*\t");
        }
        printf("\n");
    }

    printf("\n思考:为什么是 j <= i ?\n");
    printf("因为第1行打印1个, 第2行打印2个, ... 第9行打印9个\n");

    return 0;
}

