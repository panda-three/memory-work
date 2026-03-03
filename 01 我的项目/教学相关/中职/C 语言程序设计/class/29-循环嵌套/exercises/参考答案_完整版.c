#include <stdio.h>

/*
 * 循环嵌套练习题 - 完整答案版
 * 教师用：包含所有练习的完整代码
 */

// ========== 练习1：倒三角形 ==========
void practice1() {
    printf("\n========== 练习1：倒三角形 ==========\n\n");
    int i, j;

    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= 6 - i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n关键点：6 - i 让星号数递减\n");
}

// ========== 练习2：等腰三角形 ==========
void practice2() {
    printf("\n========== 练习2：等腰三角形 ==========\n\n");
    int i, j;
    int height = 5;

    for (i = 1; i <= height; i++) {
        // 打印空格（递减）
        for (j = 1; j <= height - i; j++) {
            printf(" ");
        }

        // 打印星号（奇数递增）
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }

        printf("\n");
    }

    printf("\n关键点：\n");
    printf("- 空格数：height - i（递减）\n");
    printf("- 星号数：2 * i - 1（奇数递增）\n");
}

// ========== 练习3：菱形 ==========
void practice3() {
    printf("\n========== 练习3：菱形 ==========\n\n");
    int i, j;
    int height = 5;

    // 上半部分（等腰三角形）
    for (i = 1; i <= height; i++) {
        for (j = 1; j <= height - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    // 下半部分（倒等腰三角形）
    for (i = 1; i <= height - 1; i++) {
        // 空格递增
        for (j = 1; j <= i; j++) {
            printf(" ");
        }
        // 星号递减
        for (j = 1; j <= 2 * (height - i) - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n关键点：分成上下两部分，分别处理\n");
}

// ========== 额外挑战：空心菱形 ==========
void bonus_practice() {
    printf("\n========== 挑战题：空心菱形 ==========\n\n");
    int i, j;
    int height = 5;

    // 上半部分
    for (i = 1; i <= height; i++) {
        // 空格
        for (j = 1; j <= height - i; j++) {
            printf(" ");
        }
        // 星号部分
        for (j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1) {
                printf("*");  // 只打印两端
            } else {
                printf(" ");  // 中间打空格
            }
        }
        printf("\n");
    }

    // 下半部分
    for (i = 1; i <= height - 1; i++) {
        for (j = 1; j <= i; j++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * (height - i) - 1; j++) {
            if (j == 1 || j == 2 * (height - i) - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// ========== 主函数 ==========
int main() {
    int choice;

    printf("╔══════════════════════════════════╗\n");
    printf("║   循环嵌套练习题 - 完整答案     ║\n");
    printf("╚══════════════════════════════════╝\n");

    while (1) {
        printf("\n请选择要查看的练习：\n");
        printf("1. 倒三角形\n");
        printf("2. 等腰三角形\n");
        printf("3. 菱形\n");
        printf("4. 挑战题：空心菱形\n");
        printf("0. 退出\n");
        printf("请输入选项：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                practice1();
                break;
            case 2:
                practice2();
                break;
            case 3:
                practice3();
                break;
            case 4:
                bonus_practice();
                break;
            case 0:
                printf("\n再见！\n");
                return 0;
            default:
                printf("\n无效选项，请重新选择！\n");
        }
    }

    return 0;
}
