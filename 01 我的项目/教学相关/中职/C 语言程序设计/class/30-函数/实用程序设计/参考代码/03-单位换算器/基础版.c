#include <stdio.h>

// 功能：显示主菜单
// 参数：无
// 返回值：无
void showMenu() {
    printf("\n========== 单位换算器 ==========\n");
    printf("1. 长度换算（米↔厘米）\n");
    printf("2. 温度换算（摄氏度↔华氏度）\n");
    printf("3. 退出系统\n");
    printf("===============================\n");
    printf("请选择功能（1-3）：");
}

// 功能：长度换算
// 参数：无
// 返回值：无
void convertLength() {
    int choice;
    float value;

    printf("\n1. 米转厘米\n");
    printf("2. 厘米转米\n");
    printf("请选择：");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("请输入米数：");
        scanf("%f", &value);
        printf("%.2f米 = %.2f厘米\n", value, value * 100);
    } else if(choice == 2) {
        printf("请输入厘米数：");
        scanf("%f", &value);
        printf("%.2f厘米 = %.2f米\n", value, value / 100);
    } else {
        printf("输入错误！\n");
    }
}

// 功能：温度换算
// 参数：无
// 返回值：无
void convertTemperature() {
    int choice;
    float value;

    printf("\n1. 摄氏度转华氏度\n");
    printf("2. 华氏度转摄氏度\n");
    printf("请选择：");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("请输入摄氏度：");
        scanf("%f", &value);
        float f = value * 9 / 5 + 32;
        printf("%.2f°C = %.2f°F\n", value, f);
    } else if(choice == 2) {
        printf("请输入华氏度：");
        scanf("%f", &value);
        float c = (value - 32) * 5 / 9;
        printf("%.2f°F = %.2f°C\n", value, c);
    } else {
        printf("输入错误！\n");
    }
}

int main() {
    int choice;

    printf("欢迎使用单位换算器！\n");

    while(1) {
        showMenu();
        scanf("%d", &choice);

        if(choice == 1) {
            convertLength();
        } else if(choice == 2) {
            convertTemperature();
        } else if(choice == 3) {
            printf("\n感谢使用，再见！\n");
            break;
        } else {
            printf("\n输入错误，请重新选择！\n");
        }
    }

    return 0;
}
