  #include <stdio.h>

  int main() {
      // 定义变量
      int start_hour, start_minute;    // 开始时间
      int end_hour, end_minute;        // 结束时间
      int start_total_minutes;         // 开始时间转换为总分钟数
      int end_total_minutes;           // 结束时间转换为总分钟数
      int time_diff;                   // 时间差（分钟）

      // 输入开始时间
      printf("请输入开始时间（小时 分钟）：");
      scanf("%d %d", &start_hour, &start_minute);

      // 输入结束时间
      printf("请输入结束时间（小时 分钟）：");
      scanf("%d %d", &end_hour, &end_minute);

      // 将时间转换为总分钟数进行计算
      start_total_minutes = start_hour * 60 + start_minute;
      end_total_minutes = end_hour * 60 + end_minute;

      // 计算时间差
      time_diff = end_total_minutes - start_total_minutes;

      // 输出结果
      printf("开始时间：%d:%d\n", start_hour, start_minute);
      printf("结束时间：%d:%d\n", end_hour, end_minute);
      printf("经过时间：%d分钟\n", time_diff);

      return 0;
  }
