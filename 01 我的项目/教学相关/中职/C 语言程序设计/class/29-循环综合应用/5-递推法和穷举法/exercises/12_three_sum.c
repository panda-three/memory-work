#include <stdio.h>

/*
 * 穷举法题目12：三数之和等于目标值
 */
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    int target = 10;
    int i, j, k;
    int count = 0;

    printf("数组: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n目标值: %d\n\n", target);

    printf("所有和为%d的三数组合：\n", target);

    for (i = 0; i < n - 2; i++) {
        for (j = i + 1; j < n - 1; j++) {
            for (k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == target) {
                    printf("%d + %d + %d = %d\n",
                           arr[i], arr[j], arr[k], target);
                    count++;
                }
            }
        }
    }

    printf("\n共找到 %d 种组合\n", count);

    return 0;
}
