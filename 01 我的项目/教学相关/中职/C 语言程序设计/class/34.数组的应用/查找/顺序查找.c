#include <stdio.h>

int main() {
    int arr[] = {23, 45, 16, 78, 90, 34, 56, 12, 67, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    
    printf("数组元素为: ");
    int i; 
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("请输入要查找的数字: ");
    scanf("%d", &key);
    //补index的这种写法 
    int flag=0;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
           flag=1;
		   break;  
        }
    }
  
    if (flag==1) {
        printf("查找成功！元素 %d 在数组中的位置是: 下标 %d\n", key, i);
    } else {
        printf("查找失败！数组中不存在元素 %d\n", key);
    }
    
    return 0;
}
