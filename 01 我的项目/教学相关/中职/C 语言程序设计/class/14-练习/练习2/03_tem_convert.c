#include <stdio.h>

  int main() {
      // 定义变量
      float celsius;     // 摄氏温度
      float fahrenheit;  // 华氏温度
      float kelvin;      // 开氏温度

      // 输入摄氏温度
      printf("请输入摄氏温度：");
      scanf("%f", &celsius);

      // 计算华氏温度和开氏温度
      fahrenheit = celsius * 9 / 5 + 32;  // F = C × 9 ÷ 5 + 32
      kelvin = celsius + 273;              // K = C + 273

      // 输出结果
      printf("摄氏温度：%.2f℃\n", celsius);
      printf("华氏温度：%.2f℉\n", fahrenheit);
      printf("开氏温度：%.2fK\n", kelvin);

      return 0;
  }
