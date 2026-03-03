#include <stdio.h>

int main(void)
{
    int n = 10;                 /* 前 10 项 */
    double sum = 0.0;           /* 累加和，用浮点避免整除丢失精度 */

    int fz = 1, fm = 2;  int i; /* 分子、分母，初始为第一项 1/2 */
    for ( i = 1; i <= n; ++i)
    {
        printf("%d/%d  ", fz, fm);
        
        sum += (double)fz / fm; /* 把当前项加到总和中 */

        /* 滚动更新：下一项的分子=原分母，下一项的分母=原分子+原分母 */
        int nxt_fz = fm;
        int nxt_fm = fz + fm;
        fz = nxt_fz;
        fm = nxt_fm;
    }

    printf("\nsum = %.6f\n", sum); /* 输出累加和，保留 6 位小数 */
    return 0;
}
