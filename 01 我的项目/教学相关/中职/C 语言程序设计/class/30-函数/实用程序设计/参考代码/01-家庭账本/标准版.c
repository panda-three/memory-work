#include <stdio.h>
#include <string.h>

// 全局变量
float balance = 0;        // 当前余额
int recordCount = 0;      // 记录条数

// 用于存储每条记录的信息
char types[50][10];       // 类型（收入/支出）
float amounts[50];        // 金额
char descriptions[50][50]; // 说明

// 功能：显示主菜单
// 参数：无
// 返回值：无
void showMenu() {
    printf("\n========== 家庭账本管理系统 ==========\n");
    printf("1. 记录收入\n");
    printf("2. 记录支出\n");
    printf("3. 查询余额\n");
    printf("4. 显示所有记录\n");
    printf("5. 退出系统\n");
    printf("======================================\n");
    printf("请选择功能（1-5）：");
}

// 功能：记录收入
// 参数：无
// 返回值：无
void addIncome() {
    float money;
    char desc[50];

    printf("\n请输入收入金额：");
    scanf("%f", &money);

    // 输入验证
    if(money <= 0) {
        printf("金额必须大于0！\n");
        return;
    }

    printf("请输入收入说明：");
    getchar(); // 清除缓冲区的换行符
    gets(desc);

    // 保存记录
    strcpy(types[recordCount], "收入");
    amounts[recordCount] = money;
    strcpy(descriptions[recordCount], desc);
    recordCount++;

    balance = balance + money;
    printf("记录成功！当前余额：%.2f元\n", balance);
}

// 功能：记录支出
// 参数：无
// 返回值：无
void addExpense() {
    float money;
    char desc[50];

    printf("\n请输入支出金额：");
    scanf("%f", &money);

    // 输入验证
    if(money <= 0) {
        printf("金额必须大于0！\n");
        return;
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
    printf("记录成功！当前余额：%.2f元\n", balance);
}

// 功能：查询余额
// 参数：无
// 返回值：无
void checkBalance() {
    printf("\n当前余额：%.2f元\n", balance);
    if(balance < 0) {
        printf("⚠️ 警告：您已经超支了！\n");
    }
}

// 功能：显示所有记录
// 参数：无
// 返回值：无
void showAllRecords() {
    printf("\n========== 所有记录 ==========\n");

    if(recordCount == 0) {
        printf("暂无记录\n");
        return;
    }

    printf("序号\t类型\t金额\t\t说明\n");
    printf("------------------------------------------\n");

    for(int i = 0; i < recordCount; i++) {
        printf("%d\t%s\t%.2f元\t\t%s\n",
               i+1, types[i], amounts[i], descriptions[i]);
    }

    printf("------------------------------------------\n");
    printf("当前余额：%.2f元\n", balance);
}

int main() {
    int choice;

    printf("========================================\n");
    printf("     欢迎使用家庭账本管理系统！\n");
    printf("========================================\n");

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
                printf("\n感谢使用，再见！\n");
                return 0;
            default:
                printf("\n输入错误，请输入1-5之间的数字！\n");
        }
    }

    return 0;
}
