#include <stdio.h>
#include "seqlist.cpp"
// 直接插入排序
void InsertionSort(RecType R[], int n) {
    for (int i = 1; i < n; i++) {
        RecType temp = R[i];
        int j = i - 1;
        while (j >= 0 && R[j].key > temp.key) {
            R[j + 1] = R[j];
            j--;
        }
        R[j + 1] = temp;
    }
}

// 折半插入排序
void BinaryInsertionSort(RecType R[], int n) {
    for (int i = 1; i < n; i++) {
        RecType temp = R[i];
        int low = 0;
        int high = i - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (R[mid].key > temp.key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (int j = i - 1; j >= low; j--) {
            R[j + 1] = R[j];
        }
        R[low] = temp;
    }
}

// 快速排序
int Partition(RecType R[], int low, int high) {
    RecType pivot = R[low];
    while (low < high) {
        while (low < high && R[high].key >= pivot.key) {
            high--;
        }
        R[low] = R[high];
        while (low < high && R[low].key <= pivot.key) {
            low++;
        }
        R[high] = R[low];
    }
    R[low] = pivot;
    return low;
}

void QuickSort(RecType R[], int low, int high) {
    if (low < high) {
        int pivotPos = Partition(R, low, high);
        QuickSort(R, low, pivotPos - 1);
        QuickSort(R, pivotPos + 1, high);
    }
}

// 简单选择排序
void SelectionSort(RecType R[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (R[j].key < R[minIndex].key) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(R[i], R[minIndex]);
        }
    }
}

int main() {
    RecType R1[] = {{6, 'a'}, {4, 'b'}, {9, 'c'}, {4, 'd'},  {1, 'e'},
                    {7, 'f'}, {9, 'g'}, {5, 'h'}, {10, 'i'}, {2, 'j'}};
    int n1 = sizeof(R1) / sizeof(RecType);

    // 直接插入排序
    InsertionSort(R1, n1);
    printf("直接插入排序结果：");
    DispList(R1, n1);

    // 折半插入排序
    BinaryInsertionSort(R1, n1);
    printf("折半插入排序结果：");
    DispList(R1, n1);

    // 快速排序
    QuickSort(R1, 0, n1 - 1);
    printf("快速排序结果：");
    DispList(R1, n1);

    // 简单选择排序
    SelectionSort(R1, n1);
    printf("简单选择排序结果：");
    DispList(R1, n1);

    return 0;
}
