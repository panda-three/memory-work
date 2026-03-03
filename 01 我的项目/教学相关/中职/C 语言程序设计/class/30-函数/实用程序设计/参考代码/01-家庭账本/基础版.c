#include <stdio.h>

// 全局变量：当前余额
float balance = 0;

// 功能：显示主菜单
// 参数：无
// 返回值：无
void showMenu() {
    printf("\n========== 家庭账本 ==========\n");
    printf("1. 记录收入\n");
    printf("2. 记录支出\n");
    printf("3. 查询余额\n");
    printf("4. 退出系统\n");
    printf("==============================\n");
    printf("请选择功能（1-4）：");
}

// 功能：记录收入
// 参数：无
// 返回值：无
void addIncome() {
    float money;
    printf("\n请输入收入金额：");
    scanf("%f", &money);
    balance = balance + money;
    printf("记录成功！当前余额：%.2f元\n", balance);
}

// 功能：记录支出
// 参数：无
// 返回值：无
void addExpense() {
    float money;
    printf("\n请输入支出金额：");
    scanf("%f", &money);
    balance = balance - money;
    printf("记录成功！当前余额：%.2f元\n", balance);
}

// 功能：查询余额
// 参数：无
// 返回值：无
void checkBalance() {
    printf("\n当前余额：%.2f元\n", balance);
}

int main() {
    int choice;

    printf("欢迎使用家庭账本系统！\n");

    while(1) {
        showMenu();
        scanf("%d", &choice);

        if(choice == 1) {
            addIncome();
        } else if(choice == 2) {
            addExpense();
        } else if(choice == 3) {
            checkBalance();
        } else if(choice == 4) {
            printf("\n感谢使用，再见！\n");
            break;
        } else {
            printf("\n输入错误，请重新选择！\n");
        }
    }

    return 0;
}
