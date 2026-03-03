#include <stdio.h>

/*
 * 最值问题-题目7：找出第二大的数
 */
int main() {
    int arr[10];
    int i;
    int max1, max2;  // max1是最大，max2是第二大

    printf("请输入10个整数：\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // 初始化max1和max2
    if (arr[0] > arr[1]) {
        max1 = arr[0];
        max2 = arr[1];
    } else {
        max1 = arr[1];
        max2 = arr[0];
    }

    // 遍历剩余元素
    for (i = 2; i < 10; i++) {
        if (arr[i] > max1) {
            max2 = max1;  // 原来的最大变成第二大
            max1 = arr[i];  // 更新最大
        } else if (arr[i] > max2) {
            max2 = arr[i];  // 更新第二大
        }
    }

    printf("\n最大值: %d\n", max1);
    printf("第二大: %d\n", max2);

    return 0;
}
