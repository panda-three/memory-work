#include <stdio.h>

// 全局变量
int password = 123456;  // 默认密码
float balance = 5000.0; // 账户余额

// 功能：显示主菜单
// 参数：无
// 返回值：无
void showMenu() {
    printf("\n========== 简易ATM取款机系统 ==========\n");
    printf("1. 查询余额\n");
    printf("2. 取款\n");
    printf("3. 存款\n");
    printf("4. 修改密码\n");
    printf("5. 退出系统\n");
    printf("=======================================\n");
    printf("请选择功能（1-5）：");
}

// 功能：用户登录
// 参数：无
// 返回值：登录成功返回1，失败返回0
int login() {
    int inputPwd;
    int tryCount = 0;  // 尝试次数

    printf("\n━━━━━ 用户登录 ━━━━━\n");

    while(tryCount < 3) {
        printf("请输入密码：");
        scanf("%d", &inputPwd);

        if(inputPwd == password) {
            printf("✅ 登录成功！\n");
            return 1;
        } else {
            tryCount++;
            printf("❌ 密码错误！还有%d次机会\n", 3 - tryCount);
        }
    }

    printf("⚠️  密码错误次数过多，账户已锁定！\n");
    return 0;
}

// 功能：查询余额
// 参数：无
// 返回值：无
void checkBalance() {
    printf("\n━━━━━ 余额查询 ━━━━━\n");
    printf("当前余额：%.2f元\n", balance);

    if(balance < 1000) {
        printf("💡 提示：余额不足1000元，请及时存款。\n");
    }
}

// 功能：取款
// 参数：无
// 返回值：无
void withdraw() {
    float money;

    printf("\n━━━━━ 取款服务 ━━━━━\n");
    printf("当前余额：%.2f元\n", balance);
    printf("请输入取款金额：");
    scanf("%f", &money);

    // 输入验证
    if(money <= 0) {
        printf("❌ 取款金额必须大于0！\n");
        return;
    }

    if((int)money % 100 != 0) {
        printf("❌ 取款金额必须是100的整数倍！\n");
        return;
    }

    if(money > balance) {
        printf("❌ 余额不足！当前余额：%.2f元\n", balance);
        return;
    }

    if(money > 5000) {
        printf("⚠️  单次取款金额不能超过5000元！\n");
        return;
    }

    balance = balance - money;
    printf("✅ 取款成功！\n");
    printf("取款金额：%.2f元\n", money);
    printf("当前余额：%.2f元\n", balance);
}

// 功能：存款
// 参数：无
// 返回值：无
void deposit() {
    float money;

    printf("\n━━━━━ 存款服务 ━━━━━\n");
    printf("请输入存款金额：");
    scanf("%f", &money);

    // 输入验证
    if(money <= 0) {
        printf("❌ 存款金额必须大于0！\n");
        return;
    }

    if(money > 50000) {
        printf("⚠️  单次存款金额不能超过50000元！\n");
        return;
    }

    balance = balance + money;
    printf("✅ 存款成功！\n");
    printf("存款金额：%.2f元\n", money);
    printf("当前余额：%.2f元\n", balance);
}

// 功能：修改密码
// 参数：无
// 返回值：无
void changePassword() {
    int oldPwd, newPwd, confirmPwd;

    printf("\n━━━━━ 修改密码 ━━━━━\n");
    printf("请输入原密码：");
    scanf("%d", &oldPwd);

    if(oldPwd != password) {
        printf("❌ 原密码错误！\n");
        return;
    }

    printf("请输入新密码（6位数字）：");
    scanf("%d", &newPwd);

    if(newPwd < 100000 || newPwd > 999999) {
        printf("❌ 密码必须是6位数字！\n");
        return;
    }

    printf("请再次输入新密码：");
    scanf("%d", &confirmPwd);

    if(newPwd != confirmPwd) {
        printf("❌ 两次输入的密码不一致！\n");
        return;
    }

    password = newPwd;
    printf("✅ 密码修改成功！\n");
}

int main() {
    int choice;

    printf("========================================\n");
    printf("     欢迎使用简易ATM取款机系统！\n");
    printf("========================================\n");

    // 用户登录
    if(login() == 0) {
        return 0;  // 登录失败，退出程序
    }

    // 主菜单循环
    while(1) {
        showMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                deposit();
                break;
            case 4:
                changePassword();
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
