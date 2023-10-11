#include <malloc.h>
#include <stdio.h>
void partition(int L[], int low, int high) {
  int pivot = L[low];  // 选择第一个元素作为基准值
  int i = low + 1;     // 左指针
  int j = high;        // 右指针

  while (i <= j) {
    if (L[i] <= pivot) {
      i++;
    } else if (L[j] > pivot) {
      j--;
    } else {
      // 交换L[i]与L[j]
      int temp = L[i];
      L[i] = L[j];
      L[j] = temp;
      i++;
      j--;
    }
  }

  // 将基准值放到正确的位置
  int temp = L[low];
  L[low] = L[j];
  L[j] = temp;

  // 递归处理左右两个子序列
  if (low < j - 1) {
    partition(L, low, j - 1);
  }
  if (j + 1 < high) {
    partition(L, j + 1, high);
  }
}

void quickSort(int L[], int length) { partition(L, 0, length - 1); }

void main() {}