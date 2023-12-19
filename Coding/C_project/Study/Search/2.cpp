#include <stdio.h>
#include "seqlist.cpp"

int BinarySearch(RecType R[], int n, KeyType target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (R[mid].key == target) {
            return mid;  // 返回目标值在顺序表中的位置
        } else if (R[mid].key < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // 目标值未找到，返回-1
}

int main() {
    RecType R[] = {{3, 'a'}, {4, 'b'}, {5, 'c'}, {6, 'd'},
                   {7, 'e'}, {8, 'f'}, {9, 'g'}, {10, 'h'}};
    int n = sizeof(R) / sizeof(RecType);
    int target = 7;
    int index = BinarySearch(R, n, target);
    if (index != -1) {
        printf("关键字 %d 在顺序表中的位置为 %d\n", target, index);
    } else {
        printf("关键字 %d 未找到\n", target);
    }
    return 0;
}
