 #include <stdio.h>

  int main() {
      char name[21], student_id[21], class_name[31];
      int age;

      printf("请输入姓名：");
      scanf("%s", name);
      printf("请输入学号：");
      scanf("%s", student_id);
      printf("请输入班级：");
      scanf("%s", class_name);
      printf("请输入年龄：");
      scanf("%d", &age);

      printf("================================\n");
      printf("|        个人信息卡片          |\n");
      printf("================================\n");
      printf("| 姓名：%s                 |\n", name);
      printf("| 学号：%s                |\n", student_id);
      printf("| 班级：%s              |\n", class_name);
      printf("| 年龄：%d岁                   |\n", age);
      printf("================================\n");

      return 0;
  }
