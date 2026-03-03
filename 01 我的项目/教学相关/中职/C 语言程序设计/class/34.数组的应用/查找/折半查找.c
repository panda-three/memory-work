#include <stdio.h>
int main() {
    // 注意：折半查找要求数组必须有序！
    int arr[] = {12, 23, 34, 45, 56, 67, 78, 89, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    
    printf("已排序数组元素为: ");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("请输入要查找的数字: ");
    int key;
    scanf("%d", &key);
    
    int low = 0;          // 低界（起始位置）
    int high = n - 1;     // 高界（结束位置）
    int mid;              // 中间位置
    int index=-1; 
    while (low <= high) {
        mid = (low + high) / 2;  // 计算中间位置
        if (arr[mid] == key) {
            index= mid;  // 找到，返回下标
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;  // 关键字在右半部分
        } else {
            high = mid - 1;  // 关键字在左半部分
        }
    }
    
    
    if (index != -1) {
        printf("查找成功！元素 %d 在数组中的位置是: 下标 %d\n", key, index);
    } else {
        printf("查找失败！数组中不存在元素 %d\n", key);
    }
    
    return 0;
}
