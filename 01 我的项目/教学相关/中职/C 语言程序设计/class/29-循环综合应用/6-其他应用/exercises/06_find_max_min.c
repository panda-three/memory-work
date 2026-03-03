#include <stdio.h>

/*
 * 最值问题-题目6：找出一组数中的最大值和最小值
 */
int main() {
    int arr[10];
    int i;
    int max, min;

    printf("请输入10个整数：\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // 初始化max和min为第一个元素
    max = min = arr[0];

    // 遍历数组找最大最小值
    for (i = 1; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("\n最大值: %d\n", max);
    printf("最小值: %d\n", min);

    return 0;
}
