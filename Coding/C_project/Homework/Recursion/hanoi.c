#include <stdio.h>

void hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("将盘子 1 从柱子 %c 移动到柱子 %c\n", source, destination);
        return;
    }

    hanoi(n - 1, source, destination, auxiliary);
    printf("将盘子 %d 从柱子 %c 移动到柱子 %c\n", n, source, destination);
    hanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    printf("请输入盘子的数量：");
    scanf("%d", &n);

    printf("解决汉诺塔问题的步骤：\n");
    hanoi(n, 'A', 'B', 'C');

    return 0;
}
