#include <malloc.h>
#include <stdio.h>

typedef struct student {
  int score;
  struct student *next;
} Linklist;

Linklist *creat(int n) {
  Linklist *head, *node, *end;  // 定义头节点，普通节点和为节点
  head = (Linklist *)malloc(sizeof(Linklist));  // 分配地址
  end = head;
  for (int i = 0; i < n; i++) {
    node = (Linklist *)malloc(sizeof(Linklist));
    scanf("%d", &node->score);
    end->next = node;
    end = node;
  }
  end->next = NULL;
  return head;
}