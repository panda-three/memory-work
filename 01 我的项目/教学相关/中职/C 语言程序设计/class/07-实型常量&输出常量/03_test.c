#include <stdio.h>

  int main() {
      int a, b;
      scanf("%d %d", &a, &b);

      printf("%d\n", a / b);                    // 整数除法
      printf("%f\n", (float)a / b);             // 一个转浮点
      printf("%f\n", (float)a / (float)b);      // 都转浮点

      return 0;
}
