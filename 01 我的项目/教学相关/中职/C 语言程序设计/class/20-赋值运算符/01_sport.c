#include <stdio.h>

  int main() {
      int total = 0;
      int day1, day2, day3;

      printf("周一运动(分钟)：");
      scanf("%d", &day1);
      total += day1;

      printf("周三运动(分钟)：");
      scanf("%d", &day2);
      total += day2;

      printf("周五运动(分钟)：");
      scanf("%d", &day3);
      total += day3;

      printf("\n本周运动：%d分钟\n", total);
      printf("达到150分钟目标：%d (1=是，0=否)\n", total >= 150);
      return 0;
  }
