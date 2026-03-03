 #include <stdio.h>

  int main() {
      int num;
      int sum = 0;
      int count = 0;

      printf("输入正整数累加，负数跳过，0结束：\n");

      while (1) {
          scanf("%d", &num);

          if (num == 0) {
              break;
          }

          if (num < 0) {
              printf("跳过负数\n");
              continue;
          }

          sum += num;
          count++;
      }

      printf("共输入%d个正数，总和为%d\n", count, sum);
      return 0;
  }
