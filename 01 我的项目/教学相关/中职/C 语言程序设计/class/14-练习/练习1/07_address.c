#include <stdio.h>

  int main() {
      char province[50];       // 省份
      char city[50];          // 城市
      char street[100];       // 街道
      char house_number[20];  // 门牌号
      char full_address[250]; // 完整地址
      int total_length;       // 地址总长度

      printf("请输入省份：");
      scanf("%s", province);

      printf("请输入城市：");
      scanf("%s", city);

      printf("请输入街道：");
      scanf("%s", street);

      printf("请输入门牌号：");
      scanf("%s", house_number);

      // 输出地址信息
      printf("\n===地址信息===\n");
      printf("省份：%s\n", province);
      printf("城市：%s\n", city);
      printf("街道：%s\n", street);
      printf("门牌：%s号\n", house_number);
      printf("完整地址：%s省%s市%s%s号\n", province, city, street, house_number);

      return 0;
  }
