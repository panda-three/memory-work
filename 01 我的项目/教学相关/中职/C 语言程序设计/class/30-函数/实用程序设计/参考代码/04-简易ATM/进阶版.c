#include <stdio.h>
#include <string.h>
#include <time.h>

// 全局变量
int password = 123456;     // 默认密码
float balance = 5000.0;    // 账户余额
char cardNumber[20] = "6222 0000 1234 5678";  // 卡号

// 交易记录
char transactionTypes[100][20];  // 交易类型
float transactionAmounts[100];   // 交易金额
float transactionBalances[100];  // 交易后余额
int transactionCount = 0;        // 交易记录数

// 功能：显示主菜单
// 参数：无
// 返回值：无
void showMenu() {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║        简易ATM取款机系统 v2.0          ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║  1. 查询余额                           ║\n");
    printf("║  2. 取款                               ║\n");
    printf("║  3. 存款                               ║\n");
    printf("║  4. 转账                               ║\n");
    printf("║  5. 修改密码                           ║\n");
    printf("║  6. 查询交易记录                       ║\n");
    printf("║  7. 退出系统                           ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("卡号：%s    余额：%.2f元\n", cardNumber, balance);
    printf("请选择功能（1-7）：");
}

// 功能：添加交易记录
// 参数：交易类型、交易金额
// 返回值：无
void addTransaction(char *type, float amount) {
    if(transactionCount < 100) {
        strcpy(transactionTypes[transactionCount], type);
        transactionAmounts[transactionCount] = amount;
        transactionBalances[transactionCount] = balance;
        transactionCount++;
    }
}

// 功能：用户登录
// 参数：无
// 返回值：登录成功返回1，失败返回0
int login() {
    int inputPwd;
    int tryCount = 0;  // 尝试次数

    printf("\n━━━━━━━━━━━━━━━━━━━━\n");
    printf("      用户登录\n");
    printf("━━━━━━━━━━━━━━━━━━━━\n");
    printf("卡号：%s\n", cardNumber);

    while(tryCount < 3) {
        printf("\n请输入密码：");
        scanf("%d", &inputPwd);

        if(inputPwd == password) {
            printf("✅ 登录成功！\n");
            return 1;
        } else {
            tryCount++;
            if(tryCount < 3) {
                printf("❌ 密码错误！还有%d次机会\n", 3 - tryCount);
            }
        }
    }

    printf("\n⚠️  密码错误次数过多，账户已锁定！\n");
    printf("请联系银行客服：95588\n");
    return 0;
}

// 功能：查询余额
// 参数：无
// 返回值：无
void checkBalance() {
    printf("\n━━━━━ 余额查询 ━━━━━\n");
    printf("卡号：%s\n", cardNumber);
    printf("当前余额：%.2f元\n", balance);

    if(balance < 1000) {
        printf("💡 提示：余额不足1000元，请及时存款。\n");
    } else if(balance >= 10000) {
        printf("💰 您的账户资金充裕！\n");
    }

    addTransaction("余额查询", 0);
}

// 功能：取款
// 参数：无
// 返回值：无
void withdraw() {
    float money;

    printf("\n━━━━━ 取款服务 ━━━━━\n");
    printf("当前余额：%.2f元\n", balance);
    printf("\n快捷取款：\n");
    printf("1. 100元   2. 200元   3. 500元\n");
    printf("4. 1000元  5. 2000元  6. 自定义金额\n");
    printf("请选择：");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1: money = 100; break;
        case 2: money = 200; break;
        case 3: money = 500; break;
        case 4: money = 1000; break;
        case 5: money = 2000; break;
        case 6:
            printf("请输入取款金额：");
            scanf("%f", &money);
            break;
        default:
            printf("❌ 输入错误！\n");
            return;
    }

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
        printf("如需大额取款，请到柜台办理。\n");
        return;
    }

    balance = balance - money;
    printf("\n✅ 取款成功！\n");
    printf("━━━━━━━━━━━━━━━━━━━━\n");
    printf("取款金额：%.2f元\n", money);
    printf("当前余额：%.2f元\n", balance);
    printf("━━━━━━━━━━━━━━━━━━━━\n");
    printf("请取走现金，谢谢！\n");

    addTransaction("取款", money);
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

    if((int)money % 100 != 0) {
        printf("❌ 存款金额必须是100的整数倍！\n");
        return;
    }

    if(money > 50000) {
        printf("⚠️  单次存款金额不能超过50000元！\n");
        printf("如需大额存款，请到柜台办理。\n");
        return;
    }

    balance = balance + money;
    printf("\n✅ 存款成功！\n");
    printf("━━━━━━━━━━━━━━━━━━━━\n");
    printf("存款金额：%.2f元\n", money);
    printf("当前余额：%.2f元\n", balance);
    printf("━━━━━━━━━━━━━━━━━━━━\n");

    addTransaction("存款", money);
}

// 功能：转账
// 参数：无
// 返回值：无
void transfer() {
    char targetCard[20];
    float money;
    int confirmPwd;

    printf("\n━━━━━ 转账服务 ━━━━━\n");
    printf("当前余额：%.2f元\n", balance);

    printf("请输入对方卡号：");
    scanf("%s", targetCard);

    printf("请输入转账金额：");
    scanf("%f", &money);

    // 输入验证
    if(money <= 0) {
        printf("❌ 转账金额必须大于0！\n");
        return;
    }

    if(money > balance) {
        printf("❌ 余额不足！当前余额：%.2f元\n", balance);
        return;
    }

    if(money > 50000) {
        printf("⚠️  单笔转账金额不能超过50000元！\n");
        return;
    }

    // 确认转账信息
    printf("\n━━━━━ 请确认转账信息 ━━━━━\n");
    printf("对方卡号：%s\n", targetCard);
    printf("转账金额：%.2f元\n", money);
    printf("手续费：0元\n");
    printf("合计：%.2f元\n", money);

    printf("\n请输入密码确认：");
    scanf("%d", &confirmPwd);

    if(confirmPwd != password) {
        printf("❌ 密码错误，转账失败！\n");
        return;
    }

    balance = balance - money;
    printf("\n✅ 转账成功！\n");
    printf("━━━━━━━━━━━━━━━━━━━━\n");
    printf("转账金额：%.2f元\n", money);
    printf("当前余额：%.2f元\n", balance);
    printf("━━━━━━━━━━━━━━━━━━━━\n");

    addTransaction("转账", money);
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

    // 检查新密码是否过于简单
    if(newPwd == 123456 || newPwd == 111111 || newPwd == 666666 || newPwd == 888888) {
        printf("⚠️  警告：该密码过于简单，建议使用更复杂的密码！\n");
        printf("是否继续使用？(1=是, 0=否)：");
        int confirm;
        scanf("%d", &confirm);
        if(confirm != 1) {
            printf("已取消操作。\n");
            return;
        }
    }

    printf("请再次输入新密码：");
    scanf("%d", &confirmPwd);

    if(newPwd != confirmPwd) {
        printf("❌ 两次输入的密码不一致！\n");
        return;
    }

    password = newPwd;
    printf("\n✅ 密码修改成功！\n");
    printf("请妥善保管您的新密码。\n");

    addTransaction("修改密码", 0);
}

// 功能：查询交易记录
// 参数：无
// 返回值：无
void showTransactions() {
    printf("\n━━━━━ 交易记录查询 ━━━━━\n");

    if(transactionCount == 0) {
        printf("暂无交易记录\n");
        return;
    }

    printf("┌────┬──────────┬──────────┬──────────┐\n");
    printf("│序号│ 交易类型 │ 交易金额 │ 账户余额 │\n");
    printf("├────┼──────────┼──────────┼──────────┤\n");

    // 显示最近10条记录
    int start = transactionCount > 10 ? transactionCount - 10 : 0;
    for(int i = start; i < transactionCount; i++) {
        printf("│ %2d │ %-8s │ %8.2f │ %8.2f │\n",
               i+1, transactionTypes[i],
               transactionAmounts[i], transactionBalances[i]);
    }

    printf("└────┴──────────┴──────────┴──────────┘\n");

    if(transactionCount > 10) {
        printf("💡 仅显示最近10条记录，共%d条\n", transactionCount);
    } else {
        printf("共%d条记录\n", transactionCount);
    }
}

int main() {
    int choice;

    printf("╔════════════════════════════════════════╗\n");
    printf("║                                        ║\n");
    printf("║      欢迎使用简易ATM取款机系统 v2.0    ║\n");
    printf("║                                        ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("\n💡 提示：默认密码为123456，建议首次使用修改密码\n");

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
                transfer();
                break;
            case 5:
                changePassword();
                break;
            case 6:
                showTransactions();
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
