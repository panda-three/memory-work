#include <stdio.h>

  int main() {
      char category;      // 分类代码
      int year;          // 出版年份
      int book_number;   // 图书序号
      float price;       // 价格

      printf("请输入图书分类（T/L/H）：");
      scanf("%c", &category);

      printf("请输入出版年份：");
      scanf("%d", &year);

      printf("请输入图书序号：");
      scanf("%d", &book_number);

      printf("请输入图书价格：");
      scanf("%f", &price);

      // 输出图书信息
      printf("\n===图书信息===\n");
      printf("图书编码：%c-%d-%04d\n", category, year, book_number);
      printf("分类：%c类\n", category);
      printf("出版年份：%d年\n", year);
      printf("序号：%d\n", book_number);
      printf("定价：%.2f元\n", price);

      return 0;
  }
