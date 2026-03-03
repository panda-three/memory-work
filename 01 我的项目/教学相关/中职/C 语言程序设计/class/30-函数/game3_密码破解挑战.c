/*
 * 游戏名称：密码破解挑战
 * 难度等级：⭐⭐⭐⭐
 * 教学目标：
 *   1. 综合运用多个自定义函数（函数协作）
 *   2. 练习复杂的循环控制（限制次数、提前退出）
 *   3. 练习多位数的数学运算（不用数组，用除法和取模）
 *   4. 练习复杂逻辑判断（位置+数字的双重匹配）
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 函数名：generatePassword
 * 功能：生成一个4位数密码（每位数字0-9）
 * 参数：无
 * 返回值：生成的4位数密码（1000-9999）
 */
int generatePassword() {
    // 生成1000-9999之间的随机4位数
    return rand() % 9000 + 1000;
}

/*
 * 函数名：checkGuess
 * 功能：检查猜测的密码，并给出提示
 * 参数：
 *   answer - 正确的密码
 *   guess - 玩家猜测的密码
 * 返回值：
 *   1 - 猜中了
 *   0 - 没猜中
 *
 * 核心算法：不用数组，用数学方法拆解4位数
 *   千位 = num / 1000
 *   百位 = (num / 100) % 10
 *   十位 = (num / 10) % 10
 *   个位 = num % 10
 */
int checkGuess(int answer, int guess) {
    // 拆解正确密码的4位数字
    int a1 = answer / 1000;           // 千位
    int a2 = (answer / 100) % 10;     // 百位
    int a3 = (answer / 10) % 10;      // 十位
    int a4 = answer % 10;              // 个位

    // 拆解玩家猜测的4位数字
    int g1 = guess / 1000;            // 千位
    int g2 = (guess / 100) % 10;      // 百位
    int g3 = (guess / 10) % 10;       // 十位
    int g4 = guess % 10;               // 个位

    // 统计"位置和数字都正确"的个数
    int exactMatch = 0;
    if (a1 == g1) exactMatch++;  // 千位匹配
    if (a2 == g2) exactMatch++;  // 百位匹配
    if (a3 == g3) exactMatch++;  // 十位匹配
    if (a4 == g4) exactMatch++;  // 个位匹配

    // 如果4个都匹配，说明猜中了
    if (exactMatch == 4) {
        printf("\n🎉🎉🎉 完全正确！密码就是 %d ！🎉🎉🎉\n", answer);
        return 1;  // 返回1表示猜中
    }

    // 统计"数字正确但位置错误"的个数
    int numberMatch = 0;

    // 检查g1（猜测的千位）是否出现在答案的其他位置
    if (g1 == a2 || g1 == a3 || g1 == a4) numberMatch++;
    // 检查g2（猜测的百位）是否出现在答案的其他位置
    if (g2 == a1 || g2 == a3 || g2 == a4) numberMatch++;
    // 检查g3（猜测的十位）是否出现在答案的其他位置
    if (g3 == a1 || g3 == a2 || g3 == a4) numberMatch++;
    // 检查g4（猜测的个位）是否出现在答案的其他位置
    if (g4 == a1 || g4 == a2 || g4 == a3) numberMatch++;

    // 给出提示
    printf("\n📊 提示：\n");
    printf("   ✅ 位置和数字都正确：%d 个\n", exactMatch);
    printf("   🔄 数字正确但位置错误：%d 个\n", numberMatch);

    return 0;  // 返回0表示没猜中
}

/*
 * 函数名：printWelcome
 * 功能：打印游戏欢迎界面和规则说明
 * 参数：无
 * 返回值：无
 */
void printWelcome() {
    printf("╔═══════════════════════════════════════╗\n");
    printf("║        密码破解挑战 v1.0              ║\n");
    printf("╠═══════════════════════════════════════╣\n");
    printf("║  游戏规则：                           ║\n");
    printf("║  1. 系统生成一个4位数密码             ║\n");
    printf("║  2. 你有8次机会猜测密码               ║\n");
    printf("║  3. 每次猜测后会给出两个提示：        ║\n");
    printf("║     ✅ 位置和数字都正确的个数         ║\n");
    printf("║     🔄 数字正确但位置错误的个数       ║\n");
    printf("║  4. 在8次内猜中密码即为胜利！         ║\n");
    printf("╚═══════════════════════════════════════╝\n");
}

int main() {
    int password;          // 系统生成的密码
    int userGuess;         // 玩家的猜测
    int maxAttempts = 8;   // 最多猜测次数
    int isSuccess = 0;     // 是否猜中（0=未猜中，1=猜中）
    char continueGame;     // 是否继续游戏

    // 设置随机数种子
    srand(time(NULL));

    // 显示欢迎界面
    printWelcome();

    // 游戏主循环
    do {
        // 生成新密码
        password = generatePassword();

        printf("\n🔐 新的密码已生成！开始破解吧！\n");
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

        isSuccess = 0;  // 重置成功标志

        // 猜测循环（最多8次机会）
        for (int attempt = 1; attempt <= maxAttempts; attempt++) {
            printf("\n第 %d/%d 次猜测，请输入4位数密码: ", attempt, maxAttempts);
            scanf("%d", &userGuess);

            // 输入验证
            if (userGuess < 1000 || userGuess > 9999) {
                printf("⚠️ 输入错误！请输入1000-9999之间的4位数。\n");
                attempt--;  // 不计入猜测次数，重新输入
                continue;
            }

            // 检查猜测
            isSuccess = checkGuess(password, userGuess);

            // 如果猜中了，跳出循环
            if (isSuccess) {
                printf("\n🏆 你在第 %d 次尝试中破解了密码！太厉害了！\n", attempt);
                break;
            }

            // 显示剩余机会
            if (attempt < maxAttempts) {
                printf("   💡 还有 %d 次机会，加油！\n", maxAttempts - attempt);
            }
        }

        // 如果8次都没猜中
        if (!isSuccess) {
            printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
            printf("😢 很遗憾，机会用完了！\n");
            printf("🔐 正确密码是：%d\n", password);
            printf("💪 不要气馁，再试一次吧！\n");
        }

        // 询问是否再玩一次
        printf("\n要再挑战一个新密码吗？(y/n): ");
        scanf(" %c", &continueGame);  // 注意空格

        if (continueGame == 'y' || continueGame == 'Y') {
            printf("\n\n");  // 换行，开始新一轮
        }

    } while (continueGame == 'y' || continueGame == 'Y');

    printf("\n╔═══════════════════════════════════════╗\n");
    printf("║      感谢游玩！期待下次挑战！         ║\n");
    printf("╚═══════════════════════════════════════╝\n");

    return 0;
}

/*
 * 【教学重点讲解】
 *
 * 1. 多位数拆解技巧（核心算法）：
 *    以密码 5678 为例：
 *    - 千位：5678 / 1000 = 5
 *    - 百位：5678 / 100 = 56，56 % 10 = 6
 *    - 十位：5678 / 10 = 567，567 % 10 = 7
 *    - 个位：5678 % 10 = 8
 *
 *    关键：先除再取模，逐步"剥离"每一位
 *
 * 2. 函数协作（软件工程思想）：
 *    - generatePassword() 负责生成密码
 *    - checkGuess() 负责检查和反馈
 *    - printWelcome() 负责显示界面
 *    - main() 负责流程控制
 *    每个函数职责单一，便于理解和维护
 *
 * 3. 返回值的妙用：
 *    - checkGuess() 返回 0 或 1，main() 根据返回值决定是否继续循环
 *    - 这比使用全局变量更安全、更清晰
 *
 * 【教学扩展建议】
 *
 * 1. 降低难度版本（适合基础薄弱的学生）：
 *    - 改为3位数密码（100-999）
 *    - 只给出"完全匹配"的个数，不判断"数字正确位置错误"
 *
 * 2. 提高难度版本（适合学有余力的学生）：
 *    - 改为5位数密码
 *    - 增加难度等级：简单（10次机会）、普通（8次）、困难（6次）
 *    - 添加计时功能（需要用到 time() 和 difftime()）
 *
 * 3. 职教高考题型转换：
 *    【程序填空题】：挖空拆解数字的公式
 *    【程序改错题】：故意把 % 和 / 写反
 *    【程序设计题】：给出游戏描述，要求编写 checkGuess 函数
 *
 * 【常见学生错误】
 *
 * 1. 拆解公式错误：
 *    - 错误：int a2 = answer / 100;  // 忘记取模，得到的是56而不是6
 *    - 正确：int a2 = (answer / 100) % 10;
 *
 * 2. 混淆"除"和"模"：
 *    - / 是除法（取商）：5678 / 100 = 56
 *    - % 是取模（取余）：5678 % 100 = 78
 *
 * 3. 逻辑判断错误：
 *    - 检查"数字正确位置错误"时，忘记排除"位置也正确"的情况
 *    - 本代码采用简化版：分两次判断，先判断完全匹配，再判断位置错误
 *
 * 4. break 的作用理解不清：
 *    - break 只跳出当前的 for 循环，不会跳出外层的 do-while
 *    - 如果要实现"猜中后直接结束游戏"，需要在 break 后再加判断
 *
 * 【教学建议】
 *
 * - 这个游戏综合性强，建议分两节课讲：
 *   第一节课：讲解数字拆解算法 + generatePassword 和 printWelcome 函数
 *   第二节课：讲解 checkGuess 函数的复杂逻辑 + 完整游戏流程
 *
 * - 可以先给学生一个"半成品"版本：
 *   只有 generatePassword 和 printWelcome，让学生自己实现 checkGuess
 *   这样既能锻炼编程能力，又能避免一次性理解过多内容
 */
