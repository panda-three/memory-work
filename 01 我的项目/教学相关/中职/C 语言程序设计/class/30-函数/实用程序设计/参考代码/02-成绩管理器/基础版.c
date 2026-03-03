#include <stdio.h>

// 全局变量
float scores[10];  // 存储最多10个学生的成绩
int count = 0;     // 已录入的学生人数

// 功能：显示主菜单
// 参数：无
// 返回值：无
void showMenu() {
    printf("\n========== 成绩管理器 ==========\n");
    printf("1. 录入成绩\n");
    printf("2. 查询成绩\n");
    printf("3. 计算平均分\n");
    printf("4. 退出系统\n");
    printf("===============================\n");
    printf("请选择功能（1-4）：");
}

// 功能：录入成绩
// 参数：无
// 返回值：无
void inputScore() {
    float score;

    printf("\n请输入第%d个学生的成绩：", count + 1);
    scanf("%f", &score);

    scores[count] = score;
    count++;

    printf("录入成功！已录入%d个学生成绩\n", count);
}

// 功能：查询所有成绩
// 参数：无
// 返回值：无
void showScores() {
    printf("\n========== 所有成绩 ==========\n");

    if(count == 0) {
        printf("暂无成绩记录\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        printf("学生%d：%.2f分\n", i+1, scores[i]);
    }
}

// 功能：计算平均分
// 参数：无
// 返回值：无
void calculateAverage() {
    if(count == 0) {
        printf("\n暂无成绩记录，无法计算平均分\n");
        return;
    }

    float sum = 0;
    for(int i = 0; i < count; i++) {
        sum = sum + scores[i];
    }

    float average = sum / count;
    printf("\n平均分：%.2f\n", average);
}

int main() {
    int choice;

    printf("欢迎使用成绩管理器！\n");

    while(1) {
        showMenu();
        scanf("%d", &choice);

        if(choice == 1) {
            if(count < 10) {
                inputScore();
            } else {
                printf("\n已达到最大录入数量（10个学生）！\n");
            }
        } else if(choice == 2) {
            showScores();
        } else if(choice == 3) {
            calculateAverage();
        } else if(choice == 4) {
            printf("\n感谢使用，再见！\n");
            break;
        } else {
            printf("\n输入错误，请重新选择！\n");
        }
    }

    return 0;
}
