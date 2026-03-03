#include <stdio.h>

/*
 * 九九乘法表 - 第三步:填入乘法结果
 * 把*号改成 j*i=结果
 */
int main() {
    printf("=== 九九乘法表 ===\n\n");
    int i,j ; 
    for ( i = 1; i <= 9; i++) {           // i代表被乘数(1到9)
        for ( j = 1; j <= i; j++) {       // j代表乘数(1到i)
            printf("%d*%d=%d ", j, i, j * i);  // 打印 j*i=结果
        }
        printf("\n");
    }

    return 0;
}

