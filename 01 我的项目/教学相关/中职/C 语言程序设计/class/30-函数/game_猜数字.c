/*
 * 游戏名称：幸运数字轮盘
 * 难度等级：???
 * 教学目标：
 *   1. 练习嵌套循环（外层：游戏轮次，内层：猜测次数）
 *   2. 练习函数返回值的应用（返回本轮得分）
 *   3. 练习逻辑判断（大了/小了的提示）
 *   4. 练习累加统计（总分计算）
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 函数名：playOneRound
 * 功能：进行一轮幸运数字猜测游戏
 * 参数：无
 * 返回值：本轮获得的分数（0-50分）
 *   - 猜中得分 = (6 - 猜测次数) × 10 分
 *   - 第1次猜中：50分
 *   - 第2次猜中：40分
 *   - 第3次猜中：30分
 *   - 第4次猜中：20分
 *   - 第5次猜中：10分
 *   - 5次都没猜中：0分
 */
int playOneRound() {
    int luckyNumber;    // 系统生成的幸运数字
    int userGuess;      // 玩家的猜测
    int maxAttempts = 5; // 最多猜测次数
    int score = 0;      // 本轮得分

    // 生成1-50之间的随机幸运数字
    luckyNumber = rand() % 50 + 1;

    printf("\n┌─────────────────────────────┐\n");
    printf("│   系统已生成幸运数字 (1-50)  │\n");
    printf("│   你有 5 次猜测机会！       │\n");
    printf("└─────────────────────────────┘\n");

    // 猜测循环（最多5次机会）
    int attempt; 
    for ( attempt = 1; attempt <= maxAttempts; attempt++) {
        printf("\n第 %d 次猜测，请输入: ", attempt);
        scanf("%d", &userGuess);

        // 判断猜测结果
        if (userGuess == luckyNumber) {
            // 猜中了！计算得分
            score = (6 - attempt) * 10;
            printf("\n?? 恭喜你！猜中了！幸运数字就是 %d\n", luckyNumber);
            printf("?? 你在第 %d 次猜中，获得 %d 分！\n", attempt, score);
            return score;  // 猜中后直接返回分数，结束本轮游戏
        } else if (userGuess > luckyNumber) {
            printf("? 太大了！");
        } else {
            printf("? 太小了！");
        }

        // 显示剩余机会
        if (attempt < maxAttempts) {
            printf(" 还有 %d 次机会。\n", maxAttempts - attempt);
        }
    }

    // 5次机会用完还没猜中
    printf("\n?? 很遗憾，机会用完了！幸运数字是 %d\n", luckyNumber);
    printf("?? 本轮得分：0 分\n");

    return 0;  // 没猜中，返回0分
}

/*
 * 函数名：printScoreLevel
 * 功能：根据总分打印评价等级
 * 参数：
 *   totalScore - 总分
 */
void printScoreLevel(int totalScore) {
    printf("\n╔═══════════════════════════╗\n");
    printf("║      游戏结束！总分：%-3d  ║\n", totalScore);
    printf("╠═══════════════════════════╣\n");

    if (totalScore >= 150) {
        printf("║       幸运之神！！！     ║\n");
    } else if (totalScore >= 100) {
        printf("║       超级幸运儿！       ║\n");
    } else if (totalScore >= 50) {
        printf("║       运气不错哦！       ║\n");
    } else if (totalScore >= 20) {
        printf("║        还需努力...        ║\n");
    } else {
        printf("║       运气欠佳...        ║\n");
    }

    printf("╚═══════════════════════════╝\n");
}

int main() {
    int totalScore = 0;      // 总分
    int roundScore;          // 本轮得分
    int roundNumber = 1;     // 当前轮次
    char continueGame;       // 是否继续游戏

    // 设置随机数种子
    srand(time(NULL));

    printf("╔═══════════════════════════════════╗\n");
    printf("║    欢迎来到幸运数字轮盘游戏！     ║\n");
    printf("╠═══════════════════════════════════╣\n");
    printf("║  规则说明：                       ║\n");
    printf("║  1. 系统生成1-50的幸运数字        ║\n");
    printf("║  2. 你有5次猜测机会               ║\n");
    printf("║  3. 猜中得分 = (6-次数)×10       ║\n");
    printf("║  4. 可以玩多轮，累计总分          ║\n");
    printf("╚═══════════════════════════════════╝\n");

    // 游戏主循环（外层循环：多轮游戏）
    do {
        printf("\n━━━━━━━━━ 第 %d 轮 ━━━━━━━━━\n", roundNumber);

        // 进行一轮游戏（内层循环在playOneRound函数里）
        roundScore = playOneRound();

        // 累加总分
        totalScore += roundScore;

        printf("\n当前总分：%d 分\n", totalScore);

        // 询问是否继续下一轮
        printf("\n要再玩一轮吗？(y/n): ");
        scanf(" %c", &continueGame);  // 注意空格，吸收之前的回车符

        if (continueGame == 'y' || continueGame == 'Y') {
            roundNumber++;  // 轮次+1
        }

    } while (continueGame == 'y' || continueGame == 'Y');

    // 游戏结束，显示总分和评价
    printScoreLevel(totalScore);

    printf("\n感谢游玩！再见！\n");

    return 0;
}

/*
 * 【教学扩展建议】
 *
 * 1. 基础练习：
 *    - 让学生修改游戏参数：范围改为1-100，机会改为10次
 *    - 修改计分规则：第1次猜中100分，第2次80分，第3次60分...
 *
 * 2. 进阶练习：
 *    - 添加"最佳记录"功能：记录历史最高分（使用一个变量存储）
 *    - 添加"平均分"统计：总分 ÷ 游戏轮数
 *
 * 3. 算法优化：
 *    - 引导学生思考：为什么要把一轮游戏封装成函数？
 *    - 对比：如果不用函数，代码会变成什么样？（嵌套3层循环，难以阅读）
 *
 * 【常见学生错误】
 *
 * 1. 混淆"循环次数"和"剩余次数"：
 *    - 错误：printf("还有 %d 次", attempt);
 *    - 正确：printf("还有 %d 次", maxAttempts - attempt);
 *
 * 2. 忘记在猜中后 return，导致继续循环：
 *    - 应该在猜中后立即 return score; 结束函数
 *
 * 3. 累加总分时写成赋值：
 *    - 错误：totalScore = roundScore;  // 每次都覆盖
 *    - 正确：totalScore += roundScore; // 累加
 *
 * 4. 嵌套循环理解困难：
 *    - 建议画流程图：外层while控制"玩几轮"，内层for控制"每轮猜几次"
 */
