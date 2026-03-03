#include <stdio.h>
#include <string.h>

// 全局变量
char names[50][20];   // 学生姓名
float scores[50];     // 学生成绩
int count = 0;        // 已录入的学生人数

// 功能：显示主菜单
// 参数：无
// 返回值：无
void showMenu() {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║      学生成绩管理系统 v2.0             ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║  1. 录入成绩                           ║\n");
    printf("║  2. 查询所有成绩                       ║\n");
    printf("║  3. 按姓名查询成绩                     ║\n");
    printf("║  4. 计算平均分                         ║\n");
    printf("║  5. 查找最高分和最低分                 ║\n");
    printf("║  6. 统计及格率                         ║\n");
    printf("║  7. 成绩排序                           ║\n");
    printf("║  8. 删除学生记录                       ║\n");
    printf("║  9. 退出系统                           ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("已录入学生人数：%d/50\n", count);
    printf("请选择功能（1-9）：");
}

// 功能：录入成绩
// 参数：无
// 返回值：无
void inputScore() {
    char name[20];
    float score;

    printf("\n━━━━━ 录入成绩 ━━━━━\n");
    printf("请输入学生姓名：");
    scanf("%s", name);

    // 检查是否已存在
    for(int i = 0; i < count; i++) {
        if(strcmp(names[i], name) == 0) {
            printf("⚠️  该学生已存在！当前成绩：%.2f\n", scores[i]);
            printf("是否更新成绩？(1=是, 0=否)：");
            int update;
            scanf("%d", &update);
            if(update == 1) {
                printf("请输入新成绩（0-100）：");
                scanf("%f", &score);
                if(score >= 0 && score <= 100) {
                    scores[i] = score;
                    printf("✅ 更新成功！\n");
                } else {
                    printf("❌ 成绩必须在0-100之间！\n");
                }
            }
            return;
        }
    }

    printf("请输入成绩（0-100）：");
    scanf("%f", &score);

    // 输入验证
    if(score < 0 || score > 100) {
        printf("❌ 成绩必须在0-100之间！\n");
        return;
    }

    // 保存数据
    strcpy(names[count], name);
    scores[count] = score;
    count++;

    printf("✅ 录入成功！\n");
}

// 功能：查询所有成绩
// 参数：无
// 返回值：无
void showScores() {
    printf("\n━━━━━ 所有学生成绩 ━━━━━\n");

    if(count == 0) {
        printf("暂无成绩记录\n");
        return;
    }

    printf("┌────┬──────────┬────────┬──────┐\n");
    printf("│序号│   姓名   │  成绩  │ 等级 │\n");
    printf("├────┼──────────┼────────┼──────┤\n");

    for(int i = 0; i < count; i++) {
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

        printf("│ %2d │ %-8s │ %6.2f │  %c   │\n",
               i+1, names[i], scores[i], grade);
    }

    printf("└────┴──────────┴────────┴──────┘\n");
}

// 功能：按姓名查询成绩
// 参数：无
// 返回值：无
void searchByName() {
    char name[20];

    printf("\n━━━━━ 按姓名查询 ━━━━━\n");
    printf("请输入学生姓名：");
    scanf("%s", name);

    for(int i = 0; i < count; i++) {
        if(strcmp(names[i], name) == 0) {
            printf("\n查询结果：\n");
            printf("姓名：%s\n", names[i]);
            printf("成绩：%.2f\n", scores[i]);

            if(scores[i] >= 90) {
                printf("等级：A（优秀）\n");
            } else if(scores[i] >= 80) {
                printf("等级：B（良好）\n");
            } else if(scores[i] >= 70) {
                printf("等级：C（中等）\n");
            } else if(scores[i] >= 60) {
                printf("等级：D（及格）\n");
            } else {
                printf("等级：E（不及格）\n");
            }
            return;
        }
    }

    printf("❌ 未找到该学生！\n");
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

    printf("\n━━━━━ 平均分统计 ━━━━━\n");
    printf("总人数：%d\n", count);
    printf("总分：%.2f\n", sum);
    printf("平均分：%.2f\n", average);
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

    for(int i = 1; i < count; i++) {
        if(scores[i] > max) {
            max = scores[i];
            maxIndex = i;
        }
        if(scores[i] < min) {
            min = scores[i];
            minIndex = i;
        }
    }

    printf("\n━━━━━ 最值查询 ━━━━━\n");
    printf("🏆 最高分：%.2f（%s）\n", max, names[maxIndex]);
    printf("📉 最低分：%.2f（%s）\n", min, names[minIndex]);
    printf("分差：%.2f\n", max - min);
}

// 功能：统计及格率
// 参数：无
// 返回值：无
void calculatePassRate() {
    if(count == 0) {
        printf("\n暂无成绩记录\n");
        return;
    }

    int passCount = 0;      // 及格人数
    int excellentCount = 0; // 优秀人数（90分以上）
    int goodCount = 0;      // 良好人数（80-89分）

    for(int i = 0; i < count; i++) {
        if(scores[i] >= 60) {
            passCount++;
        }
        if(scores[i] >= 90) {
            excellentCount++;
        } else if(scores[i] >= 80) {
            goodCount++;
        }
    }

    float passRate = (float)passCount / count * 100;
    float excellentRate = (float)excellentCount / count * 100;

    printf("\n━━━━━ 成绩统计分析 ━━━━━\n");
    printf("总人数：%d\n", count);
    printf("及格人数：%d（及格率：%.2f%%）\n", passCount, passRate);
    printf("不及格人数：%d\n", count - passCount);
    printf("优秀人数：%d（优秀率：%.2f%%）\n", excellentCount, excellentRate);
    printf("良好人数：%d\n", goodCount);

    if(passRate >= 90) {
        printf("\n✅ 整体成绩优秀！\n");
    } else if(passRate >= 70) {
        printf("\n💡 整体成绩良好，继续努力！\n");
    } else {
        printf("\n⚠️  及格率偏低，需要加强学习！\n");
    }
}

// 功能：成绩排序（降序）
// 参数：无
// 返回值：无
void sortScores() {
    if(count == 0) {
        printf("\n暂无成绩记录\n");
        return;
    }

    // 冒泡排序（降序）
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - 1 - i; j++) {
            if(scores[j] < scores[j+1]) {
                // 交换成绩
                float tempScore = scores[j];
                scores[j] = scores[j+1];
                scores[j+1] = tempScore;

                // 交换姓名
                char tempName[20];
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], tempName);
            }
        }
    }

    printf("\n✅ 排序完成！（按成绩从高到低）\n");
    showScores();
}

// 功能：删除学生记录
// 参数：无
// 返回值：无
void deleteStudent() {
    char name[20];

    printf("\n━━━━━ 删除记录 ━━━━━\n");
    printf("请输入要删除的学生姓名：");
    scanf("%s", name);

    for(int i = 0; i < count; i++) {
        if(strcmp(names[i], name) == 0) {
            printf("确认删除 %s 的成绩记录？(1=是, 0=否)：", name);
            int confirm;
            scanf("%d", &confirm);

            if(confirm != 1) {
                printf("已取消操作。\n");
                return;
            }

            // 删除记录（将后面的记录前移）
            for(int j = i; j < count - 1; j++) {
                strcpy(names[j], names[j+1]);
                scores[j] = scores[j+1];
            }

            count--;
            printf("✅ 删除成功！\n");
            return;
        }
    }

    printf("❌ 未找到该学生！\n");
}

int main() {
    int choice;

    printf("╔════════════════════════════════════════╗\n");
    printf("║                                        ║\n");
    printf("║     欢迎使用学生成绩管理系统 v2.0      ║\n");
    printf("║                                        ║\n");
    printf("╚════════════════════════════════════════╝\n");

    while(1) {
        showMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(count < 50) {
                    inputScore();
                } else {
                    printf("\n已达到最大录入数量（50个学生）！\n");
                }
                break;
            case 2:
                showScores();
                break;
            case 3:
                searchByName();
                break;
            case 4:
                calculateAverage();
                break;
            case 5:
                findMaxMin();
                break;
            case 6:
                calculatePassRate();
                break;
            case 7:
                sortScores();
                break;
            case 8:
                deleteStudent();
                break;
            case 9:
                printf("\n━━━━━━━━━━━━━━━━━━━━\n");
                printf("  感谢使用，再见！\n");
                printf("━━━━━━━━━━━━━━━━━━━━\n");
                return 0;
            default:
                printf("\n❌ 输入错误，请输入1-9之间的数字！\n");
        }
    }

    return 0;
}
