#include <stdio.h>

  int main() {
      int student_id;      // 学号
      char chinese_grade;  // 语文等级
      char math_grade;     // 数学等级
      char english_grade;  // 英语等级

      printf("请输入学号：");
      scanf("%d", &student_id);

      printf("请输入语文成绩等级：");
      scanf(" %c", &chinese_grade);

      printf("请输入数学成绩等级：");
      scanf(" %c", &math_grade);

      printf("请输入英语成绩等级：");
      scanf(" %c", &english_grade);

      // 输出成绩单
      printf("\n===成绩单===\n");
      printf("学号：%d\n", student_id);
      printf("语文：%c\n", chinese_grade);
      printf("数学：%c\n", math_grade);
      printf("英语：%c\n", english_grade);

      return 0;
  }

