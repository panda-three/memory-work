#include <stdio.h>

/*
 * 综合应用-题目20：成绩等级统计
 */
int main() {
    int score;
    int grade[5] = {0};  // A, B, C, D, E的人数
    int total = 0;

    printf("====== 成绩等级统计系统 ======\n");
    printf("请输入学生成绩（输入-1结束）：\n\n");

    while (1) {
        printf("请输入成绩: ");
        scanf("%d", &score);

        if (score == -1) {
            break;
        }

        if (score < 0 || score > 100) {
            printf("成绩无效，请重新输入！\n");
            continue;
        }

        total++;

        if (score >= 90) {
            grade[0]++;  // A级
            printf("等级: A\n\n");
        } else if (score >= 80) {
            grade[1]++;  // B级
            printf("等级: B\n\n");
        } else if (score >= 70) {
            grade[2]++;  // C级
            printf("等级: C\n\n");
        } else if (score >= 60) {
            grade[3]++;  // D级
            printf("等级: D\n\n");
        } else {
            grade[4]++;  // E级
            printf("等级: E\n\n");
        }
    }

    printf("\n========== 统计结果 ==========\n");
    printf("总人数: %d\n\n", total);
    printf("A级 (90-100): %d人\n", grade[0]);
    printf("B级 (80-89):  %d人\n", grade[1]);
    printf("C级 (70-79):  %d人\n", grade[2]);
    printf("D级 (60-69):  %d人\n", grade[3]);
    printf("E级 (0-59):   %d人\n", grade[4]);

    return 0;
}
