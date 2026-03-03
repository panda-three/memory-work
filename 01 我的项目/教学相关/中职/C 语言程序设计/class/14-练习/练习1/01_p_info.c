#include <stdio.h>

  int main() {
      char name_initial;    // 姓名首字母
      char gender;         // 性别
      char blood_type;     // 血型
      int age;            // 年龄

      printf("请输入姓名首字母：");
      scanf("%c", &name_initial);

      printf("请输入性别（M/F）：");
      scanf(" %c", &gender);  // 注意前面的空格

      printf("请输入血型（A/B/O）：");
      scanf(" %c", &blood_type);

      printf("请输入年龄：");
      scanf("%d", &age);

      // 输出个人信息
      printf("\n===个人信息===\n");
      printf("姓名首字母：%c\n", name_initial);
      printf("性别：%c\n", gender);
      printf("血型：%c型\n", blood_type);
      printf("年龄：%d岁\n", age);

      return 0;
  }

