#include <stdio.h>
  int main() {
      int start, end, count = 0;

      printf("请输入范围的起始值：");
      scanf("%d", &start);
      printf("请输入范围的结束值：");
      scanf("%d", &end);

      printf("\n在%d到%d范围内，既能被3整除又能被5整除的数字有：\n", start, end);
	  int i;
      for (i = start; i <= end; i++) {
          if (i % 3 == 0 && i % 5 == 0) {
              printf("%d ", i);
              count++;
          }
      }

      if (count == 0) {
          printf("没有找到符合条件的数字");
      }

      printf("\n共找到 %d 个数字\n", count);

      // 知识扩展：能被3和5整除等价于能被15整除
      printf("\n知识扩展：能被3和5整除 = 能被15整除\n");

      return 0;
  }
