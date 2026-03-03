  #include <stdio.h>

  int main() {
      int likes;
      printf("点赞数：");
      scanf("%d", &likes);

      int views = likes * 20;
      int comments = likes / 10;
      int rate = (likes + comments) * 100 / views;

      printf("播放量：%d\n", views);
      printf("评论数：%d\n", comments);
      printf("互动率：%d%%\n", rate);
      return 0;
  }
