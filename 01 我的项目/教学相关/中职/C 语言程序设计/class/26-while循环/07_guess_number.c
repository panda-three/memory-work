#include <stdio.h>

  int main() {
      int target = 66;  // 目标数字
      int guess;
      int count = 0;

      printf("猜一个1-100之间的数字\n");

      while (1) {
          printf("请输入你的猜测：");
          scanf("%d", &guess);
          count++;

          if (guess == target) {
              printf("恭喜你猜对了！用了%d次\n", count);
              break;
          } else if (guess > target) {
              printf("太大了！再试试\n");
          } else {
              printf("太小了！再试试\n");
          }
      }

      return 0;
  }
