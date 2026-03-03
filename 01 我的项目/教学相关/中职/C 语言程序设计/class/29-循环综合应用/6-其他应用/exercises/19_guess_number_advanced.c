#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 综合应用-题目19：猜数字游戏（完整版）
 */
int main() {
    int secret, guess;
    int count = 0;
    int maxTries = 10;

    srand(time(NULL));
    secret = rand() % 100 + 1;

    printf("====== 猜数字游戏 ======\n");
    printf("我已经想好了一个1-100之间的数字\n");
    printf("你最多有%d次机会\n\n", maxTries);

    while (count < maxTries) {
        printf("第%d次猜测，请输入: ", count + 1);
        scanf("%d", &guess);
        count++;

        if (guess > secret) {
            printf("太大了！还剩%d次机会\n\n", maxTries - count);
        } else if (guess < secret) {
            printf("太小了！还剩%d次机会\n\n", maxTries - count);
        } else {
            printf("\n恭喜你！猜对了！\n");
            printf("正确答案是 %d\n", secret);
            printf("你一共用了 %d 次\n", count);

            if (count <= 3) {
                printf("评价：天才！\n");
            } else if (count <= 6) {
                printf("评价：很棒！\n");
            } else {
                printf("评价：不错！\n");
            }

            return 0;
        }
    }

    printf("\n很遗憾，机会用完了！\n");
    printf("正确答案是 %d\n", secret);

    return 0;
}
