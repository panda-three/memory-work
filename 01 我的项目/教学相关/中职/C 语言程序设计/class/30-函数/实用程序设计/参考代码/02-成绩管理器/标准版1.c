#include <stdio.h>
#include <string.h>

// 全局变量
char names[10][20];  // 学生姓名
float scores[10];    // 学生成绩
int count = 0;       // 已录入的学生人数

// 功能：显示主菜单
// 参数：无
// 返回值：无
void showMenu() {
    printf("\n========== 学生成绩管理系统 ==========\n");
    printf("1. 录入成绩\n");
    printf("2. 查询成绩\n");
    printf("3. 计算平均分\n");
    printf("4. 查找最高分和最低分\n");
    printf("5. 统计及格率\n");
    printf("6. 退出系统\n");
    printf("======================================\n");
    printf("已录入学生人数：%d/10\n", count);
    printf("请选择功能（1-6）：");
}

// 功能：录入成绩
// 参数：无
// 返回值：无
void inputScore() {
    char name[20];
    float score;

    printf("\n请输入学生姓名：");
    scanf("%s", name);

    printf("请输入成绩（0-100）：");
    scanf("%f", &score);

    // 输入验证
    if(score < 0 || score > 100) {
        printf("? 成绩必须在0-100之间！\n");
        return;
    }

    // 保存数据
    strcpy(names[count], name);
    scores[count] = score;
    count++;

    printf("? 录入成功！\n");
}

// 功能：查询成绩
// 参数：无
// 返回值：无
void showScores() {
    printf("\n========== 所有学生成绩 ==========\n");

    if(count == 0) {
        printf("暂无成绩记录\n");
        return;
    }

    printf("序号\t姓名\t\t成绩\t\t等级\n");
    printf("------------------------------------------\n");
    int i; 
    for(i = 0; i < count; i++) {
        char grade;
        if(scores[i] >= 90) {
            grade = 'A';
        } else if(scores[i] >= 80) {
            grade = 'B';
        } else if(scores[i] >= 70) {
            grade = 'C';
        } else if(scores[i] >= 60) {
            grade = 'D';
        } else {
            grade = 'E';
        }

        printf("%d\t%-10s\t%.2f\t\t%c\n", i+1, names[i], scores[i], grade);
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
    int i; 
    for(i = 0; i < count; i++) {
        sum = sum + scores[i];
    }

    float average = sum / count;
    printf("\n班级平均分：%.2f\n", average);
}

// 功能：查找最高分和最低分
// 参数：无
// 返回值：无
void findMaxMin() {
    if(count == 0) {
        printf("\n暂无成绩记录\n");
        return;
    }

    float max = scores[0];
    float min = scores[0];
    int maxIndex = 0;
    int minIndex = 0;
    int i;
    for( i = 1; i < count; i++) {
        if(scores[i] > max) {
            max = scores[i];
            maxIndex = i;
        }
        if(scores[i] < min) {
            min = scores[i];
            minIndex = i;
        }
    }

    printf("\n最高分：%.2f（%s）\n", max, names[maxIndex]);
    printf("最低分：%.2f（%s）\n", min, names[minIndex]);
}

// 功能：统计及格率
// 参数：无
// 返回值：无
void calculatePassRate() {
    if(count == 0) {
        printf("\n暂无成绩记录\n");
        return;
    }

    int passCount = 0;  // 及格人数
    int i;
    for( i = 0; i < count; i++) {
        if(scores[i] >= 60) {
            passCount++;
        }
    }

    float passRate = (float)passCount / count * 100;

    printf("\n========== 及格率统计 ==========\n");
    printf("总人数：%d\n", count);
    printf("及格人数：%d\n", passCount);
    printf("不及格人数：%d\n", count - passCount);
    printf("及格率：%.2f%%\n", passRate);
}

int main() {
    int choice;

    printf("========================================\n");
    printf("     欢迎使用学生成绩管理系统！\n");
    printf("========================================\n");

    while(1) {
        showMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(count < 10) {
                    inputScore();
                } else {
                    printf("\n已达到最大录入数量（10个学生）！\n");
                }
                break;
            case 2:
                showScores();
                break;
            case 3:
                calculateAverage();
                break;
            case 4:
                findMaxMin();
                break;
            case 5:
                calculatePassRate();
                break;
            case 6:
                printf("\n感谢使用，再见！\n");
                return 0;
            default:
                printf("\n输入错误，请输入1-6之间的数字！\n");
        }
    }

    return 0;
}

