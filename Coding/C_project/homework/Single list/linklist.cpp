/*
采用头插法插入a,b,c,d,e元素
输出单链表h
输出单链表h长度
判断单链表h是否为空
输出单链表h的第3个元素
输出元素a的位置
在第4个元素位置上插入f元素
输出单链表h
删除h的第3个元素
输出单链表h
释放单链表h
*/

#include <malloc.h>
#include <stdio.h>
typedef char ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode* next;  // 指向后继结点
} LinkNode;              // 单链表结点类型
void CreateListF(LinkNode*& L, ElemType a[], int n) {
    *L = NULL;

    for (int i = 0; i < n; i++) {
        LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
        if (newNode == NULL) {
            printf("内存分配失败。\n");
            return;
        }

        newNode->data = a[i];

        newNode->next = *L;
        *L = newNode;
    }
}  // 头插法建立单链表

void CreateListR(LinkNode*& L, ElemType a[], int n) {}  // 尾插法建立单链表
void InitList(LinkNode*& L) {
    *head = NULL;
}  // 初始化单链表

void DestroyList(LinkNode*& L) {
    LinkNode* currentNode = *head;
    LinkNode* nextNode;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
}  // 销毁线性表

void exportList(LinkNode*& L) {
    LinkNode* current = head;

    while (current = != NULL) {
        printf("%d\n", current->data);
        current = current->data;
    }

    printf("\n");
}  // 输出单链表

void isEmpty(LinkNode* head) {
    if (head == NULL) {
        printf("为空");
    } else {
        printf("非空");
    }
}  // 判断单链表是否为空
int exportElement(LinkNode*& L, int position) {
    LinkNode* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == position) {
            return current->data;
        }

        current = current->next;
        count++;
    }
}  // 输出单链表的第某个元素
void exportElementPosition(LinkNode*& L, ElemType intput) {
    LinkNode* current = head;
    int count = 0;
    while (current != NULL) {
        if (intput == current.data) {
            return count;
        }
        current = current->next;
        count++;
    }
}  // 输出某个元素的位置

void deleteElement(LinkNode** head, int element) {
    LinkNode* current = *head;
    LinkNode* previous = NULL;

    // 查找要删除的节点以及其前一个节点
    while (current != NULL && current->data != element) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found.\n");
        return;
    }

    // 如果要删除的节点是头节点
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

int exportListLength(ListNode* head) {
    int length = 0;
    ListNode* current = head;

    while (current != nullptr) {
        length++;
        current = current->next;
    }

    return length;
}  // 输出单链表长度