// 顺序表运算算法
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

#define MaxSize 50
typedef int ElemType;
typedef struct {
  ElemType data[MaxSize];                         // 存放顺序表元素
  int length;                                     // 存放顺序表的长度
} SqList;                                         // 声明顺序表的类型
void CreateList(SqList *&L, ElemType a[], int n)  // 整体建立顺序表
{
  L = (SqList *)malloc(sizeof(SqList));
  for (int i = 0; i < n; i++) L->data[i] = a[i];
  L->length = n;
}
void InitList(SqList *&L)  // 初始化线性表
{
  L = (SqList *)malloc(sizeof(SqList));  // 分配存放线性表的空间
  L->length = 0;
}
void DestroyList(SqList *&L)  // 销毁线性表
{
  free(L);
}
bool ListEmpty(SqList *L)  // 判线性表是否为空表
{
  return (L->length == 0);
}
int ListLength(SqList *L)  // 求线性表的长度
{
  return (L->length);
}
void DispList(SqList *L)  // 输出线性表
{
  for (int i = 0; i < L->length; i++) printf("%d ", L->data[i]);
  printf("\n");
}
bool GetElem(SqList *L, int i, ElemType &e)  // 求线性表中第i个元素值
{
  if (i < 1 || i > L->length) return false;
  e = L->data[i - 1];
  return true;
}
int LocateElem(SqList *L, ElemType e)  // 查找第一个值域为e的元素序号
{
  int i = 0;
  while (i < L->length && L->data[i] != e) i++;
  if (i >= L->length)
    return 0;
  else
    return i + 1;
}
bool ListInsert(SqList *&L, int i, ElemType e)  // 插入第i个元素
{
  int j;
  if (i < 1 || i > L->length + 1) return false;
  i--;                             // 将顺序表位序转化为elem下标
  for (j = L->length; j > i; j--)  // 将data[i]及后面元素后移一个位置
    L->data[j] = L->data[j - 1];
  L->data[i] = e;
  L->length++;  // 顺序表长度增1
  return true;
}
bool ListDelete(SqList *&L, int i, ElemType &e)  // 删除第i个元素
{
  int j;
  if (i < 1 || i > L->length) return false;
  i--;  // 将顺序表位序转化为elem下标
  e = L->data[i];
  for (j = i; j < L->length - 1; j++)  // 将data[i]之后的元素前移一个位置
    L->data[j] = L->data[j + 1];
  L->length--;  // 顺序表长度减1
  return true;
}
