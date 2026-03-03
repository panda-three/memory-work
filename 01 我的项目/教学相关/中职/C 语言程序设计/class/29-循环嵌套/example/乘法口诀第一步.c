#include <stdio.h>

/*
 * 九九乘法表 - 第一步:打印9行9列的框架
 * 先不管乘法,只打印结构
 */
int main() {
    printf("=== 第一步:打印9行9列 ===\n\n");
     int i,j ; 
    for ( i = 1; i <= 9; i++) {        // 9行
        for ( j = 1; j <= 9; j++) {    // 9列
            printf("*\t");  // \t是制表符,让输出整齐
        }
        printf("\n");
    }

    return 0;
}

