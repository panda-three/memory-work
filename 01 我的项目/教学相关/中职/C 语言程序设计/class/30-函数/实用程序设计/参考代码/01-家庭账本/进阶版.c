#include <stdio.h>
#include <string.h>

// 全局变量
float balance = 1000.0;   // 初始余额1000元
int recordCount = 0;      // 记录条数

// 用于存储每条记录的信息
char types[100][10];       // 类型（收入/支出）
float amounts[100];        // 金额
char descriptions[100][50]; // 说明

// 功能：显示主菜单（带颜色和美化）
// 参数：无
// 返回值：无
void showMenu() {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║      家庭账本管理系统 v2.0             ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║  1. 记录收入                           ║\n");
    printf("║  2. 记录支出                           ║\n");
    printf("║  3. 查询余额                           ║\n");
    printf("║  4. 显示所有记录                       ║\n");
    printf("║  5. 统计收支情况                       ║\n");
    printf("║  6. 删除记录                           ║\n");
    printf("║  7. 退出系统                           ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("当前余额：%.2f元\n", balance);
    printf("请选择功能（1-7）：");
}

// 功能：记录收入
// 参数：无
// 返回值：无
void addIncome() {
    float money;
    char desc[50];

    printf("\n━━━━━ 记录收入 ━━━━━\n");
    printf("请输入收入金额：");
    scanf("%f", &money);

    // 输入验证
    if(money <= 0) {
        printf("❌ 金额必须大于0！\n");
        return;
    }

    printf("请输入收入说明：");
    getchar();
    gets(desc);

    // 保存记录
    strcpy(types[recordCount], "收入");
    amounts[recordCount] = money;
    strcpy(descriptions[recordCount], desc);
    recordCount++;

    balance = balance + money;
    printf("✅ 记录成功！当前余额：%.2f元\n", balance);
}

// 功能：记录支出
// 参数：无
// 返回值：无
void addExpense() {
    float money;
    char desc[50];

    printf("\n━━━━━ 记录支出 ━━━━━\n");
    printf("请输入支出金额：");
    scanf("%f", &money);

    // 输入验证
    if(money <= 0) {
        printf("❌ 金额必须大于0！\n");
        return;
    }

    // 余额不足警告
    if(money > balance) {
        printf("⚠️  警告：此次支出将导致余额不足！\n");
        printf("当前余额：%.2f元，支出金额：%.2f元\n", balance, money);
        printf("是否继续？(1=是, 0=否)：");
        int confirm;
        scanf("%d", &confirm);
        if(confirm != 1) {
            printf("已取消操作。\n");
            return;
        }
    }

    printf("请输入支出说明：");
    getchar();
    gets(desc);

    // 保存记录
    strcpy(types[recordCount], "支出");
    amounts[recordCount] = money;
    strcpy(descriptions[recordCount], desc);
    recordCount++;

    balance = balance - money;
    printf("✅ 记录成功！当前余额：%.2f元\n", balance);
}

// 功能：查询余额
// 参数：无
// 返回值：无
void checkBalance() {
    printf("\n━━━━━ 余额查询 ━━━━━\n");
    printf("当前余额：%.2f元\n", balance);

    if(balance < 0) {
        printf("⚠️  警告：您已经超支 %.2f元！\n", -balance);
    } else if(balance < 100) {
        printf("💡 提示：余额不足100元，请注意节约开支。\n");
    } else {
        printf("✅ 财务状况良好！\n");
    }
}

// 功能：显示所有记录
// 参数：无
// 返回值：无
void showAllRecords() {
    printf("\n━━━━━ 所有记录 ━━━━━\n");

    if(recordCount == 0) {
        printf("暂无记录\n");
        return;
    }

    printf("┌────┬────────┬──────────┬────────────────────┐\n");
    printf("│序号│ 类型   │   金额   │       说明         │\n");
    printf("├────┼────────┼──────────┼────────────────────┤\n");

    for(int i = 0; i < recordCount; i++) {
        printf("│ %2d │  %s  │ %8.2f │ %-18s │\n",
               i+1, types[i], amounts[i], descriptions[i]);
    }

    printf("└────┴────────┴──────────┴────────────────────┘\n");
    printf("当前余额：%.2f元\n", balance);
}

// 功能：统计收支情况
// 参数：无
// 返回值：无
void statistics() {
    float totalIncome = 0;   // 总收入
    float totalExpense = 0;  // 总支出

    printf("\n━━━━━ 收支统计 ━━━━━\n");

    if(recordCount == 0) {
        printf("暂无记录，无法统计\n");
        return;
    }

    // 计算总收入和总支出
    for(int i = 0; i < recordCount; i++) {
        if(strcmp(types[i], "收入") == 0) {
            totalIncome = totalIncome + amounts[i];
        } else {
            totalExpense = totalExpense + amounts[i];
        }
    }

    printf("📊 统计结果：\n");
    printf("   总收入：%.2f元\n", totalIncome);
    printf("   总支出：%.2f元\n", totalExpense);
    printf("   净收入：%.2f元\n", totalIncome - totalExpense);
    printf("   当前余额：%.2f元\n", balance);

    // 分析
    if(totalExpense > totalIncome) {
        printf("\n⚠️  本期支出大于收入，请注意控制开支！\n");
    } else {
        printf("\n✅ 本期收支平衡良好！\n");
    }
}

// 功能：删除记录
// 参数：无
// 返回值：无
void deleteRecord() {
    int num;

    printf("\n━━━━━ 删除记录 ━━━━━\n");

    if(recordCount == 0) {
        printf("暂无记录可删除\n");
        return;
    }

    showAllRecords();
    printf("\n请输入要删除的记录序号：");
    scanf("%d", &num);

    if(num < 1 || num > recordCount) {
        printf("❌ 序号无效！\n");
        return;
    }

    // 调整余额
    if(strcmp(types[num-1], "收入") == 0) {
        balance = balance - amounts[num-1];
    } else {
        balance = balance + amounts[num-1];
    }

    // 删除记录（将后面的记录前移）
    for(int i = num-1; i < recordCount-1; i++) {
        strcpy(types[i], types[i+1]);
        amounts[i] = amounts[i+1];
        strcpy(descriptions[i], descriptions[i+1]);
    }

    recordCount--;
    printf("✅ 删除成功！当前余额：%.2f元\n", balance);
}

int main() {
    int choice;

    printf("╔════════════════════════════════════════╗\n");
    printf("║                                        ║\n");
    printf("║     欢迎使用家庭账本管理系统 v2.0      ║\n");
    printf("║                                        ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("\n💡 提示：系统已为您设置初始余额1000元\n");

    while(1) {
        showMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addIncome();
                break;
            case 2:
                addExpense();
                break;
            case 3:
                checkBalance();
                break;
            case 4:
                showAllRecords();
                break;
            case 5:
                statistics();
                break;
            case 6:
                deleteRecord();
                break;
            case 7:
                printf("\n━━━━━━━━━━━━━━━━━━━━\n");
                printf("  感谢使用，再见！\n");
                printf("━━━━━━━━━━━━━━━━━━━━\n");
                return 0;
            default:
                printf("\n❌ 输入错误，请输入1-7之间的数字！\n");
        }
    }

    return 0;
}
