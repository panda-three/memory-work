#include <stdio.h>
  int main() {
      printf("100到999之间的完全数：\n");
      printf("（完全数 = 所有真因子的和）\n\n");

      int found = 0;
	  int num;
      for ( num = 100; num <= 999; num++) {
          int sum = 0;

          // 找出num的所有真因子并求和
          printf("分析 %d 的因子：", num);
          int i;
          for (i = 1; i < num; i++) {
              if (num % i == 0) {
                  printf("%d ", i);
                  sum += i;
              }
          }

          printf("→ 因子和 = %d", sum);

          if (sum == num) {
              printf("%d 这是完全数！\n",num);
              found++;
          } else {
              printf("\n");
          }
      }

      if (found == 0) {
          printf("\n在100到999范围内没有找到完全数。\n");
          printf("提示：最小的几个完全数是 6, 28, 496, 8128...\n");
      } else {
          printf("\n共找到 %d 个完全数\n", found);
      }

      return 0;
  }
