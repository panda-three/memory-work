#include <stdio.h>

  int main() {
      int total = 2 * 1024;  // 2GB = 2048MB
      int used;

      printf("已用流量(MB)：");
      scanf("%d", &used);

      int left = total - used;
      int percent = used * 100 / total;

      printf("剩余：%dMB\n", left);
      printf("已用：%d%%\n", percent);
      return 0;
  }
