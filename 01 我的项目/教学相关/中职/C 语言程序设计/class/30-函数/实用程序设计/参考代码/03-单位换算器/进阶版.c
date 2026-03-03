#include <stdio.h>

// 功能：显示主菜单
// 参数：无
// 返回值：无
void showMenu() {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║      多功能单位换算器 v2.0             ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║  1. 长度换算                           ║\n");
    printf("║  2. 重量换算                           ║\n");
    printf("║  3. 温度换算                           ║\n");
    printf("║  4. 时间换算                           ║\n");
    printf("║  5. 货币换算                           ║\n");
    printf("║  6. 面积换算                           ║\n");
    printf("║  7. 查看换算历史                       ║\n");
    printf("║  8. 退出系统                           ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("请选择功能（1-8）：");
}

// 全局变量：存储换算历史
char history[50][100];  // 换算记录
int historyCount = 0;   // 记录条数

// 功能：添加换算历史
// 参数：记录内容
// 返回值：无
void addHistory(char *record) {
    if(historyCount < 50) {
        sprintf(history[historyCount], "%s", record);
        historyCount++;
    }
}

// 功能：长度换算
// 参数：无
// 返回值：无
void convertLength() {
    int choice;
    float value, result;
    char record[100];

    printf("\n━━━━━ 长度换算 ━━━━━\n");
    printf("1. 米 → 厘米\n");
    printf("2. 厘米 → 米\n");
    printf("3. 米 → 英尺\n");
    printf("4. 英尺 → 米\n");
    printf("5. 米 → 英寸\n");
    printf("6. 英寸 → 米\n");
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
            result = value * 100;
            printf("✅ %.2f米 = %.2f厘米\n", value, result);
            sprintf(record, "长度: %.2f米 → %.2f厘米", value, result);
            break;
        case 2:
            result = value / 100;
            printf("✅ %.2f厘米 = %.2f米\n", value, result);
            sprintf(record, "长度: %.2f厘米 → %.2f米", value, result);
            break;
        case 3:
            result = value * 3.28084;
            printf("✅ %.2f米 = %.2f英尺\n", value, result);
            sprintf(record, "长度: %.2f米 → %.2f英尺", value, result);
            break;
        case 4:
            result = value / 3.28084;
            printf("✅ %.2f英尺 = %.2f米\n", value, result);
            sprintf(record, "长度: %.2f英尺 → %.2f米", value, result);
            break;
        case 5:
            result = value * 39.3701;
            printf("✅ %.2f米 = %.2f英寸\n", value, result);
            sprintf(record, "长度: %.2f米 → %.2f英寸", value, result);
            break;
        case 6:
            result = value / 39.3701;
            printf("✅ %.2f英寸 = %.2f米\n", value, result);
            sprintf(record, "长度: %.2f英寸 → %.2f米", value, result);
            break;
        default:
            printf("❌ 输入错误！\n");
            return;
    }

    addHistory(record);
}

// 功能：重量换算
// 参数：无
// 返回值：无
void convertWeight() {
    int choice;
    float value, result;
    char record[100];

    printf("\n━━━━━ 重量换算 ━━━━━\n");
    printf("1. 千克 → 克\n");
    printf("2. 克 → 千克\n");
    printf("3. 千克 → 磅\n");
    printf("4. 磅 → 千克\n");
    printf("5. 千克 → 吨\n");
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
            result = value * 1000;
            printf("✅ %.2f千克 = %.2f克\n", value, result);
            sprintf(record, "重量: %.2f千克 → %.2f克", value, result);
            break;
        case 2:
            result = value / 1000;
            printf("✅ %.2f克 = %.2f千克\n", value, result);
            sprintf(record, "重量: %.2f克 → %.2f千克", value, result);
            break;
        case 3:
            result = value * 2.20462;
            printf("✅ %.2f千克 = %.2f磅\n", value, result);
            sprintf(record, "重量: %.2f千克 → %.2f磅", value, result);
            break;
        case 4:
            result = value / 2.20462;
            printf("✅ %.2f磅 = %.2f千克\n", value, result);
            sprintf(record, "重量: %.2f磅 → %.2f千克", value, result);
            break;
        case 5:
            result = value / 1000;
            printf("✅ %.2f千克 = %.2f吨\n", value, result);
            sprintf(record, "重量: %.2f千克 → %.2f吨", value, result);
            break;
        default:
            printf("❌ 输入错误！\n");
            return;
    }

    addHistory(record);
}

// 功能：温度换算
// 参数：无
// 返回值：无
void convertTemperature() {
    int choice;
    float value, result;
    char record[100];

    printf("\n━━━━━ 温度换算 ━━━━━\n");
    printf("1. 摄氏度 → 华氏度\n");
    printf("2. 华氏度 → 摄氏度\n");
    printf("3. 摄氏度 → 开尔文\n");
    printf("4. 开尔文 → 摄氏度\n");
    printf("请选择：");
    scanf("%d", &choice);

    printf("请输入数值：");
    scanf("%f", &value);

    switch(choice) {
        case 1:
            result = value * 9 / 5 + 32;
            printf("✅ %.2f°C = %.2f°F\n", value, result);
            sprintf(record, "温度: %.2f°C → %.2f°F", value, result);
            break;
        case 2:
            result = (value - 32) * 5 / 9;
            printf("✅ %.2f°F = %.2f°C\n", value, result);
            sprintf(record, "温度: %.2f°F → %.2f°C", value, result);
            break;
        case 3:
            if(value < -273.15) {
                printf("❌ 温度不能低于绝对零度（-273.15°C）！\n");
                return;
            }
            result = value + 273.15;
            printf("✅ %.2f°C = %.2fK\n", value, result);
            sprintf(record, "温度: %.2f°C → %.2fK", value, result);
            break;
        case 4:
            if(value < 0) {
                printf("❌ 开尔文温度不能为负数！\n");
                return;
            }
            result = value - 273.15;
            printf("✅ %.2fK = %.2f°C\n", value, result);
            sprintf(record, "温度: %.2fK → %.2f°C", value, result);
            break;
        default:
            printf("❌ 输入错误！\n");
            return;
    }

    addHistory(record);
}

// 功能：时间换算
// 参数：无
// 返回值：无
void convertTime() {
    int choice;
    float value, result;
    char record[100];

    printf("\n━━━━━ 时间换算 ━━━━━\n");
    printf("1. 小时 → 分钟\n");
    printf("2. 分钟 → 小时\n");
    printf("3. 分钟 → 秒\n");
    printf("4. 秒 → 分钟\n");
    printf("5. 天 → 小时\n");
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
            result = value * 60;
            printf("✅ %.2f小时 = %.2f分钟\n", value, result);
            sprintf(record, "时间: %.2f小时 → %.2f分钟", value, result);
            break;
        case 2:
            result = value / 60;
            printf("✅ %.2f分钟 = %.2f小时\n", value, result);
            sprintf(record, "时间: %.2f分钟 → %.2f小时", value, result);
            break;
        case 3:
            result = value * 60;
            printf("✅ %.2f分钟 = %.2f秒\n", value, result);
            sprintf(record, "时间: %.2f分钟 → %.2f秒", value, result);
            break;
        case 4:
            result = value / 60;
            printf("✅ %.2f秒 = %.2f分钟\n", value, result);
            sprintf(record, "时间: %.2f秒 → %.2f分钟", value, result);
            break;
        case 5:
            result = value * 24;
            printf("✅ %.2f天 = %.2f小时\n", value, result);
            sprintf(record, "时间: %.2f天 → %.2f小时", value, result);
            break;
        default:
            printf("❌ 输入错误！\n");
            return;
    }

    addHistory(record);
}

// 功能：货币换算
// 参数：无
// 返回值：无
void convertCurrency() {
    int choice;
    float value, result;
    char record[100];

    // 汇率（2024年参考值，实际使用时可自定义）
    float usdRate = 7.2;   // 美元汇率
    float eurRate = 7.8;   // 欧元汇率
    float jpyRate = 0.05;  // 日元汇率

    printf("\n━━━━━ 货币换算 ━━━━━\n");
    printf("1. 人民币 → 美元\n");
    printf("2. 美元 → 人民币\n");
    printf("3. 人民币 → 欧元\n");
    printf("4. 欧元 → 人民币\n");
    printf("5. 人民币 → 日元\n");
    printf("请选择：");
    scanf("%d", &choice);

    printf("请输入金额：");
    scanf("%f", &value);

    if(value < 0) {
        printf("❌ 金额不能为负数！\n");
        return;
    }

    switch(choice) {
        case 1:
            result = value / usdRate;
            printf("✅ %.2f元 = %.2f美元（汇率: %.2f）\n", value, result, usdRate);
            sprintf(record, "货币: %.2f元 → %.2f美元", value, result);
            break;
        case 2:
            result = value * usdRate;
            printf("✅ %.2f美元 = %.2f元（汇率: %.2f）\n", value, result, usdRate);
            sprintf(record, "货币: %.2f美元 → %.2f元", value, result);
            break;
        case 3:
            result = value / eurRate;
            printf("✅ %.2f元 = %.2f欧元（汇率: %.2f）\n", value, result, eurRate);
            sprintf(record, "货币: %.2f元 → %.2f欧元", value, result);
            break;
        case 4:
            result = value * eurRate;
            printf("✅ %.2f欧元 = %.2f元（汇率: %.2f）\n", value, result, eurRate);
            sprintf(record, "货币: %.2f欧元 → %.2f元", value, result);
            break;
        case 5:
            result = value / jpyRate;
            printf("✅ %.2f元 = %.2f日元（汇率: %.2f）\n", value, result, jpyRate);
            sprintf(record, "货币: %.2f元 → %.2f日元", value, result);
            break;
        default:
            printf("❌ 输入错误！\n");
            return;
    }

    addHistory(record);
    printf("💡 提示：汇率为参考值，实际交易请以银行汇率为准。\n");
}

// 功能：面积换算
// 参数：无
// 返回值：无
void convertArea() {
    int choice;
    float value, result;
    char record[100];

    printf("\n━━━━━ 面积换算 ━━━━━\n");
    printf("1. 平方米 → 平方厘米\n");
    printf("2. 平方米 → 平方英尺\n");
    printf("3. 平方米 → 亩\n");
    printf("4. 亩 → 平方米\n");
    printf("请选择：");
    scanf("%d", &choice);

    printf("请输入数值：");
    scanf("%f", &value);

    if(value < 0) {
        printf("❌ 面积不能为负数！\n");
        return;
    }

    switch(choice) {
        case 1:
            result = value * 10000;
            printf("✅ %.2f平方米 = %.2f平方厘米\n", value, result);
            sprintf(record, "面积: %.2f平方米 → %.2f平方厘米", value, result);
            break;
        case 2:
            result = value * 10.7639;
            printf("✅ %.2f平方米 = %.2f平方英尺\n", value, result);
            sprintf(record, "面积: %.2f平方米 → %.2f平方英尺", value, result);
            break;
        case 3:
            result = value / 666.67;
            printf("✅ %.2f平方米 = %.4f亩\n", value, result);
            sprintf(record, "面积: %.2f平方米 → %.4f亩", value, result);
            break;
        case 4:
            result = value * 666.67;
            printf("✅ %.2f亩 = %.2f平方米\n", value, result);
            sprintf(record, "面积: %.2f亩 → %.2f平方米", value, result);
            break;
        default:
            printf("❌ 输入错误！\n");
            return;
    }

    addHistory(record);
}

// 功能：查看换算历史
// 参数：无
// 返回值：无
void showHistory() {
    printf("\n━━━━━ 换算历史记录 ━━━━━\n");

    if(historyCount == 0) {
        printf("暂无换算记录\n");
        return;
    }

    printf("┌────┬────────────────────────────────┐\n");
    printf("│序号│          换算记录              │\n");
    printf("├────┼────────────────────────────────┤\n");

    for(int i = 0; i < historyCount; i++) {
        printf("│ %2d │ %-30s │\n", i+1, history[i]);
    }

    printf("└────┴────────────────────────────────┘\n");
    printf("共 %d 条记录\n", historyCount);
}

int main() {
    int choice;

    printf("╔════════════════════════════════════════╗\n");
    printf("║                                        ║\n");
    printf("║    欢迎使用多功能单位换算器 v2.0       ║\n");
    printf("║                                        ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("\n💡 提示：本系统会自动记录您的换算历史\n");

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
                convertCurrency();
                break;
            case 6:
                convertArea();
                break;
            case 7:
                showHistory();
                break;
            case 8:
                printf("\n━━━━━━━━━━━━━━━━━━━━\n");
                printf("  感谢使用，再见！\n");
                printf("━━━━━━━━━━━━━━━━━━━━\n");
                return 0;
            default:
                printf("\n❌ 输入错误，请输入1-8之间的数字！\n");
        }
    }

    return 0;
}
