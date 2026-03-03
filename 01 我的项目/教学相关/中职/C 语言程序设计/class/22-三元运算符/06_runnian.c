#include <stdio.h>

  int main() {
      int year;
      int isLeap;
  
      printf("请输入年份：");
      scanf("%d", &year);

      // 使用逻辑运算符判断闰年
      isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

      // 使用三元运算符输出结果
      printf("%d年%s闰年\n", year, isLeap ? "是" : "不是");
      printf("2月有%d天\n", isLeap ? 29 : 28);

      return 0;
  }
