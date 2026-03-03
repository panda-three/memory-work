#include <stdio.h>
  int main() {
      char ch;

      printf("请输入一个字符：");
      scanf("%c", &ch);

      if (ch >= 'A' && ch <= 'Z') {
          printf("'%c'是大写字母\n", ch);
      } else if (ch >= 'a' && ch <= 'z') {
          printf("'%c'是小写字母\n", ch);
      } else if (ch >= '0' && ch <= '9') {
          printf("'%c'是数字字符\n", ch);
      } else {
          printf("'%c'是其他字符\n", ch);
      }

      return 0;
  }
