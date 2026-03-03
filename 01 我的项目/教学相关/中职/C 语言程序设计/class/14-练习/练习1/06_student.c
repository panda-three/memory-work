#include <stdio.h>

  int main() {
      char name[50];        // 姓名
      char school[100];     // 学校名称
      char major[50];       // 专业名称
      int student_id;       // 学号

      printf("请输入学生姓名：");
      scanf("%s", name);

      printf("请输入学校名称：");
      scanf("%s", school);

      printf("请输入专业名称：");
      scanf("%s", major);

      printf("请输入学号：");
      scanf("%d", &student_id);

      // 输出学生档案
      printf("\n===学生档案===\n");
      printf("姓名：%s\n", name);
      printf("学校：%s\n", school);
      printf("专业：%s\n", major);
      printf("学号：%d\n", student_id);
      printf("档案编号：%s-%s-%d\n", school, major, student_id);

      return 0;
  }

