 #include <stdio.h>
  int main() {
      int num;

      printf("请输入一个整数：");
      scanf("%d", &num);

      if (num >= 0) {
          printf("这是非负数\n");
      }

      return 0;
  }
