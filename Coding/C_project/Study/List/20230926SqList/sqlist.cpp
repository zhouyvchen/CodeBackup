#include <malloc.h>
#include <stdio.h>

#define MaxSize 50
typedef char ElemType;

typedef struct {
  ElemType data[MaxSize];  // 存放顺序表元素
  int length;              // 存放顺序表的长度
} SqList;

// 整体建立顺序表
void CreateList(SqList*& L, ElemType a[], int n) {
  L = (SqList*)malloc(sizeof(SqList));
  for (int i = 0; i < n; i++) {
    L->data[i] = a[i];
  }
  L->length = n;
}

// 初始化顺序表
void InitList(SqList*& L) {
  L = (SqList*)malloc(sizeof(SqList));
  L->length = 0;
}

// 销毁顺序表
void DestroyList(SqList*& L) { free(L); }

// 判断是否顺序表是否为空
bool ListEmpty(SqList* L) { return (L->length == 0); }

// 插入元素
bool ListInsert(SqList*& L, int pos, ElemType e) {
  if (pos < 1 || pos > L->length + 1 || L->length == MaxSize) {
    // 处理插入位置非法或顺序表已满的情况
    return false;
  }

  for (int i = L->length; i >= pos; i--) {
    L->data[i] = L->data[i - 1];
  }

  L->data[pos - 1] = e;
  L->length++;

  return true;  // 插入成功
}

// 删除顺序表中指定位置的元素
bool ListDelete(SqList*& L, int pos) {
  if (pos < 1 || pos > L->length) {
    // 处理删除位置非法的情况
    return false;
  }

  for (int i = pos; i < L->length; i++) {
    L->data[i - 1] = L->data[i];
  }

  L->length--;

  return true;  // 删除成功
}

// 输出顺序表的元素
void PrintList(SqList* L) {
  for (int i = 0; i < L->length; i++) {
    printf("%c ", L->data[i]);
  }
  printf("\n");
}

bool GetElem(SqList* L, int i, ElemType &e)
{
	if(i < 1 || i > L->length)
		return false;
	e = L->data[i - 1];
	return true;
}