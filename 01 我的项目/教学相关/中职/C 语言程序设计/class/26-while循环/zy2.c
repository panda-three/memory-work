/* 折纸厚度超过珠穆朗玛峰高度所需次数 */
#include <stdio.h>

int main(void)
{
    double thickness = 0.1;          /* 初始厚度，单位：毫米 */
    double height    = 8844430.0;    /* 珠穆朗玛峰高度，毫米 */
    int    count     = 0;

    while (thickness < height) {
        thickness *= 2;
        ++count;
    }

    printf("需要折叠 %d 次\n", count);
    return 0;
}
