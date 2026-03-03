#include <stdio.h>

  int main() {
      int password = 1234;
      int input;
      int attempts = 3;

      while (attempts > 0) {
          printf("请输入密码（剩余%d次）：", attempts);
          scanf("%d", &input);

          if (input == password) {
              printf("密码正确，登录成功！\n");
              break;
          }

          attempts--;
          if (attempts == 0) {
              printf("账户已锁定！\n");
          } else {
              printf("密码错误！\n");
          }
      }
      return 0;
  }
