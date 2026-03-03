#include <stdio.h>

// 全局变量
int password = 123456;  // 默认密码
float balance = 5000.0; // 账户余额

// 功能：显示主菜单
// 参数：无
// 返回值：无
void showMenu() {
    printf("\n========== ATM取款机 ==========\n");
    printf("1. 查询余额\n");
    printf("2. 取款\n");
    printf("3. 存款\n");
    printf("4. 退出系统\n");
    printf("==============================\n");
    printf("请选择功能（1-4）：");
}

// 功能：查询余额
// 参数：无
// 返回值：无
void checkBalance() {
    printf("\n当前余额：%.2f元\n", balance);
}

// 功能：取款
// 参数：无
// 返回值：无
void withdraw() {
    float money;

    printf("\n请输入取款金额：");
    scanf("%f", &money);

    if(money <= 0) {
        printf("取款金额必须大于0！\n");
        return;
    }

    if(money > balance) {
        printf("余额不足！当前余额：%.2f元\n", balance);
        return;
    }

    balance = balance - money;
    printf("取款成功！取款金额：%.2f元\n", money);
    printf("当前余额：%.2f元\n", balance);
}

// 功能：存款
// 参数：无
// 返回值：无
void deposit() {
    float money;

    printf("\n请输入存款金额：");
    scanf("%f", &money);

    if(money <= 0) {
        printf("存款金额必须大于0！\n");
        return;
    }

    balance = balance + money;
    printf("存款成功！存款金额：%.2f元\n", money);
    printf("当前余额：%.2f元\n", balance);
}

int main() {
    int inputPwd;
    int choice;

    printf("========== 欢迎使用ATM取款机 ==========\n");

    // 用户登录
    printf("请输入密码：");
    scanf("%d", &inputPwd);

    if(inputPwd != password) {
        printf("密码错误！\n");
        return 0;
    }

    printf("登录成功！\n");

    // 主菜单循环
    while(1) {
        showMenu();
        scanf("%d", &choice);

        if(choice == 1) {
            checkBalance();
        } else if(choice == 2) {
            withdraw();
        } else if(choice == 3) {
            deposit();
        } else if(choice == 4) {
            printf("\n感谢使用，再见！\n");
            break;
        } else {
            printf("\n输入错误，请重新选择！\n");
        }
    }

    return 0;
}
