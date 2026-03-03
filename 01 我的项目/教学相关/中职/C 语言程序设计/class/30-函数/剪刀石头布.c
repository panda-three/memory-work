/*
 * 游戏名称：石头剪刀布对战
 * 难度等级：??
 * 教学目标：
 *   1. 练习随机数生成 (rand() 和 srand())
 *   2. 练习自定义函数封装 (判断胜负的函数)
 *   3. 练习多分支选择 (if-else 或 switch)
 *   4. 练习循环实现多轮对战 (while 循环)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 函数名：judgeWinner
 * 功能：判断石头剪刀布的胜负
 * 参数：
 *   player - 玩家的选择 (1=石头, 2=剪刀, 3=布)
 *   computer - 电脑的选择 (1=石头, 2=剪刀, 3=布)
 * 返回值：
 *   1 - 玩家获胜
 *   0 - 平局
 *   -1 - 电脑获胜
 */
int judgeWinner(int player, int computer) {
    // 平局的情况
    if (player == computer) {
        return 0;
    }

    // 玩家获胜的三种情况：石头赢剪刀、剪刀赢布、布赢石头
    if ((player == 1 && computer == 2) ||  // 石头赢剪刀
        (player == 2 && computer == 3) ||  // 剪刀赢布
        (player == 3 && computer == 1)) {  // 布赢石头
        return 1;
    }

    // 其他情况都是电脑获胜
    return -1;
}

/*
 * 函数名：printChoice
 * 功能：将数字转换为对应的出拳名称并打印
 * 参数：
 *   choice - 出拳选择 (1=石头, 2=剪刀, 3=布)
 */
void printChoice(int choice) {
    if (choice == 1) {
        printf("石头");
    } else if (choice == 2) {
        printf("剪刀");
    } else if (choice == 3) {
        printf("布");
    }
}

int main() {
    int playerChoice;      // 玩家的选择
    int computerChoice;    // 电脑的选择
    int result;            // 比赛结果
    char continueGame;     // 是否继续游戏

    // 设置随机数种子（使用当前时间，保证每次运行结果不同）
    srand(time(NULL)); 

    printf("===============================\n");
    printf("    欢迎来到石头剪刀布游戏！    \n");
    printf("===============================\n\n");

    // 游戏主循环
    do {
        // 玩家输入
        printf("请出拳 (1=石头, 2=剪刀, 3=布): ");
        scanf("%d", &playerChoice);

        // 输入验证
        if (playerChoice < 1 || playerChoice > 3) {
            printf("输入错误！请输入1-3之间的数字。\n\n");
            continue;  // 跳过本次循环，重新输入
        }

        // 电脑随机出拳 (生成1-3之间的随机数)
        computerChoice = rand() % 3 + 1;

        // 显示双方的选择
        printf("\n你出了: ");
        printChoice(playerChoice);
        printf("\n电脑出了: ");
        printChoice(computerChoice);
        printf("\n\n");

        // 判断胜负
        result = judgeWinner(playerChoice, computerChoice);

        if (result == 1) {
            printf("?? 恭喜！你赢了！\n");
        } else if (result == 0) {
            printf("?? 平局！再来一次吧！\n");
        } else {
            printf("?? 很遗憾，你输了！\n");
        }

        // 询问是否继续游戏
        printf("\n要再玩一局吗？(y/n): ");
        scanf(" %c", &continueGame);  // 注意：%c前面有空格，用于吸收之前的回车符
        printf("\n");

    } while (continueGame == 'y' || continueGame == 'Y');

    printf("===============================\n");
    printf("    感谢游玩！再见！    \n");
    printf("===============================\n");

    return 0;
}


