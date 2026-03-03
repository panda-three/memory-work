  #include <stdio.h>
  int main() {
      int choice;

      printf("========== 学生信息管理系统 ==========\n");
      printf("1. 查看信息\n");
      printf("2. 修改信息\n");
      printf("3. 删除信息\n");
      printf("4. 退出系统\n");
      printf("5. 安全退出\n");
      printf("6. 强制退出\n");
      printf("7. 关于软件\n");
      printf("8. 帮助文档\n");
      printf("=====================================\n");
      printf("请选择功能（1-8）：");
      scanf("%d", &choice);

      switch (choice) {
          case 1:
              printf("正在查看学生信息...\n");
              printf("学号：20230001, 姓名：张三, 成绩：85\n");
              break;
          case 2:
              printf("正在修改学生信息...\n");
              printf("请输入新的信息进行修改\n");
              break;
          case 3:
              printf("正在删除学生信息...\n");
              printf("确认删除？(y/n)\n");
              break;
          case 4:
          case 5:
          case 6:
              printf("感谢使用！系统即将退出...\n");
              printf("再见！\n");
              break;
          case 7:
          case 8:
              printf("学生信息管理系统 v1.0\n");
              printf("开发者：C语言学习小组\n");
              printf("如需帮助，请查看用户手册\n");
              break;
          default:
              printf("无效选择！请输入1-8之间的数字\n");
              break;
      }

      return 0;
  }

