#include <stdio.h>

// 功能：显示主菜单
// 参数：无
// 返回值：无
void showMenu() {
    printf("\n========== 多功能单位换算器 ==========\n");
    printf("1. 长度换算\n");
    printf("2. 重量换算\n");
    printf("3. 温度换算\n");
    printf("4. 时间换算\n");
    printf("5. 退出系统\n");
    printf("======================================\n");
    printf("请选择功能（1-5）：");
}

// 功能：长度换算
// 参数：无
// 返回值：无
void convertLength() {
    int choice;
    float value;

    printf("\n━━━━━ 长度换算 ━━━━━\n");
    printf("1. 米 → 厘米\n");
    printf("2. 厘米 → 米\n");
    printf("3. 米 → 英尺\n");
    printf("4. 英尺 → 米\n");
    printf("请选择：");
    scanf("%d", &choice);

    printf("请输入数值：");
    scanf("%f", &value);

    if(value < 0) {
        printf("❌ 长度不能为负数！\n");
        return;
    }

    switch(choice) {
        case 1:
            printf("%.2f米 = %.2f厘米\n", value, value * 100);
            break;
        case 2:
            printf("%.2f厘米 = %.2f米\n", value, value / 100);
            break;
        case 3:
            printf("%.2f米 = %.2f英尺\n", value, value * 3.28084);
            break;
        case 4:
            printf("%.2f英尺 = %.2f米\n", value, value / 3.28084);
            break;
        default:
            printf("❌ 输入错误！\n");
    }
}

// 功能：重量换算
// 参数：无
// 返回值：无
void convertWeight() {
    int choice;
    float value;

    printf("\n━━━━━ 重量换算 ━━━━━\n");
    printf("1. 千克 → 克\n");
    printf("2. 克 → 千克\n");
    printf("3. 千克 → 磅\n");
    printf("4. 磅 → 千克\n");
    printf("请选择：");
    scanf("%d", &choice);

    printf("请输入数值：");
    scanf("%f", &value);

    if(value < 0) {
        printf("❌ 重量不能为负数！\n");
        return;
    }

    switch(choice) {
        case 1:
            printf("%.2f千克 = %.2f克\n", value, value * 1000);
            break;
        case 2:
            printf("%.2f克 = %.2f千克\n", value, value / 1000);
            break;
        case 3:
            printf("%.2f千克 = %.2f磅\n", value, value * 2.20462);
            break;
        case 4:
            printf("%.2f磅 = %.2f千克\n", value, value / 2.20462);
            break;
        default:
            printf("❌ 输入错误！\n");
    }
}

// 功能：温度换算
// 参数：无
// 返回值：无
void convertTemperature() {
    int choice;
    float value;

    printf("\n━━━━━ 温度换算 ━━━━━\n");
    printf("1. 摄氏度 → 华氏度\n");
    printf("2. 华氏度 → 摄氏度\n");
    printf("3. 摄氏度 → 开尔文\n");
    printf("请选择：");
    scanf("%d", &choice);

    printf("请输入数值：");
    scanf("%f", &value);

    switch(choice) {
        case 1:
            printf("%.2f°C = %.2f°F\n", value, value * 9 / 5 + 32);
            break;
        case 2:
            printf("%.2f°F = %.2f°C\n", value, (value - 32) * 5 / 9);
            break;
        case 3:
            if(value < -273.15) {
                printf("❌ 温度不能低于绝对零度（-273.15°C）！\n");
            } else {
                printf("%.2f°C = %.2fK\n", value, value + 273.15);
            }
            break;
        default:
            printf("❌ 输入错误！\n");
    }
}

// 功能：时间换算
// 参数：无
// 返回值：无
void convertTime() {
    int choice;
    float value;

    printf("\n━━━━━ 时间换算 ━━━━━\n");
    printf("1. 小时 → 分钟\n");
    printf("2. 分钟 → 小时\n");
    printf("3. 分钟 → 秒\n");
    printf("4. 秒 → 分钟\n");
    printf("请选择：");
    scanf("%d", &choice);

    printf("请输入数值：");
    scanf("%f", &value);

    if(value < 0) {
        printf("❌ 时间不能为负数！\n");
        return;
    }

    switch(choice) {
        case 1:
            printf("%.2f小时 = %.2f分钟\n", value, value * 60);
            break;
        case 2:
            printf("%.2f分钟 = %.2f小时\n", value, value / 60);
            break;
        case 3:
            printf("%.2f分钟 = %.2f秒\n", value, value * 60);
            break;
        case 4:
            printf("%.2f秒 = %.2f分钟\n", value, value / 60);
            break;
        default:
            printf("❌ 输入错误！\n");
    }
}

int main() {
    int choice;

    printf("========================================\n");
    printf("     欢迎使用多功能单位换算器！\n");
    printf("========================================\n");

    while(1) {
        showMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertWeight();
                break;
            case 3:
                convertTemperature();
                break;
            case 4:
                convertTime();
                break;
            case 5:
                printf("\n感谢使用，再见！\n");
                return 0;
            default:
                printf("\n❌ 输入错误，请输入1-5之间的数字！\n");
        }
    }

    return 0;
}
