#include <stdio.h>

/*
 * 综合应用-题目23：约瑟夫环问题（简化版）
 */
int main() {
    int n = 10;  // 总人数
    int m = 3;   // 报数
    int people[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  // 1表示还在圈内
    int count;
    int pos = 0;
    int remaining = n;

    printf("约瑟夫环问题：\n");
    printf("%d个人围成圈，报到%d的人出列\n\n", n, m);

    printf("出列顺序：\n");

    while (remaining > 1) {
        count = 0;

        while (count < m) {
            if (people[pos] == 1) {
                count++;
            }

            if (count < m) {
                pos = (pos + 1) % n;
            }
        }

        printf("第%d号出列\n", pos + 1);
        people[pos] = 0;  // 标记为出列
        remaining--;

        // 找下一个还在圈内的人
        pos = (pos + 1) % n;
        while (people[pos] == 0) {
            pos = (pos + 1) % n;
        }
    }

    // 找最后剩下的人
    for (pos = 0; pos < n; pos++) {
        if (people[pos] == 1) {
            printf("\n最后剩下的是第%d号\n", pos + 1);
            break;
        }
    }

    return 0;
}
