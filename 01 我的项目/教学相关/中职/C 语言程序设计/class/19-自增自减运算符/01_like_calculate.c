#include <stdio.h>

  int main() {
      int likes = 100;
      printf("初始点赞数：%d\n", likes);

      printf("有人点赞：%d\n", ++likes);
      printf("又有人点赞：%d\n", ++likes);
      printf("再有人点赞：%d\n", ++likes);
      printf("有人取消：%d\n", --likes);
      printf("又有人取消：%d\n", --likes);

      printf("最终点赞数：%d\n", likes);
      return 0;
  }
