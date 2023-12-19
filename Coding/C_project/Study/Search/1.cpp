#include <stdio.h>
#include "seqlist.cpp"

int SequentialSearch(RecType R[], int n, KeyType target) {
    for (int i = 0; i < n; i++) {
        if (R[i].key == target) {
            return i;  // 返回目标值在顺序表中的位置
        }
    }
    return -1;  // 目标值未找到，返回-1
}

int main() {
    RecType R[] = {{6, 'a'}, {8, 'b'}, {9, 'c'}, {4, 'd'},
                   {1, 'e'}, {7, 'f'}, {8, 'g'}, {6, 'h'}};
    int n = sizeof(R) / sizeof(RecType);
    int target = 7;
    int index = SequentialSearch(R, n, target);
    if (index != -1) {
        printf("关键字 %d 在顺序表中的位置为 %d\n", target, index);
    } else {
        printf("关键字 %d 未找到\n", target);
    }
    return 0;
}
