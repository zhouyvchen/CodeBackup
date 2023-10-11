#include "sqlist.cpp"

int main() {
  SqList* L;
  ElemType e;

  printf("顺序表的基本运算如下:\n");

  // (1) 初始化顺序表L
  InitList(L);

  // (2) 依次插入a,b,c,d,e元素
  ListInsert(L, 1, 'a');
  ListInsert(L, 2, 'b');
  ListInsert(L, 3, 'c');
  ListInsert(L, 4, 'd');
  ListInsert(L, 5, 'e');

  // (3) 输出顺序表L
  printf("输出顺序表L:");
  PrintList(L);

  // (4) 输出顺序表L的长度
  printf("顺序表长度为%d", L->length);

  // (5) 判断顺序表L是否为空
  printf("判断顺序表L是否为空: %s\n", ListEmpty(L) ? "是" : "否");

  // (6) 输出顺序表L的第3个元素
  printf("输出顺序表L的第3个元素: %c\n", GetElem(L, 3, e));

  // (7) 输出元素a的位置
  //  printf("  (7) 输出元素a的位置: %d\n", LocateElem(L, 'a'));

  // (8) 在第4个元素位置上插入f元素
  ListInsert(L, 4, 'f');

  // (9) 输出顺序表L
  printf("  (9) 输出顺序表L:");
  PrintList(L);

  // (10) 删除L的第3个元素
  ListDelete(L, 3);

  // (11) 释放顺序表L
  DestroyList(L);

  return 0;
}