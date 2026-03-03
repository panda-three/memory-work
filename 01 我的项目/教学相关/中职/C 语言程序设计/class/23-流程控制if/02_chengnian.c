 #include <stdio.h>
  int main() {
      int age;

      printf("请输入您的年龄：");
      scanf("%d", &age);

      if (age >= 18) {
          printf("您已经成年了！\n");
      } else {
          printf("您还未成年\n");
      }

      return 0;
  }
