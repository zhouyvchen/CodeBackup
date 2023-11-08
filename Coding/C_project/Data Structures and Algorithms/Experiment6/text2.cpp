//
// Created by bokeboke on 2023/10/24.
//
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct ListNode {
    int val;
    struct ListNode *next;
};

// 创建新节点
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// 释放链表内存
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// 打印链表
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// 在第一个最大值节点之前插入节点
void insertBeforeMax(struct ListNode* head, int x) {
    struct ListNode* maxNode = NULL;
    struct ListNode* prevMaxNode = NULL;
    struct ListNode* newNode = createNode(x);

    // 找到第一个最大值节点及其前驱节点
    struct ListNode* current = head->next;
    struct ListNode* prev = head;
    while (current != NULL) {
        if (current->val > maxNode->val) {
            maxNode = current;
            prevMaxNode = prev;
        }
        prev = current;
        current = current->next;
    }

    // 在最大值节点之前插入新节点
    prevMaxNode->next = newNode;
    newNode->next = maxNode;
}

int main() {
    // 创建原始链表
    struct ListNode* head = createNode(-1); // 带头结点
    head->next = createNode(4);
    head->next->next = createNode(10);
    head->next->next->next = createNode(7);
    head->next->next->next->next = createNode(12);
    head->next->next->next->next->next = createNode(2);
    head->next->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next->next = createNode(12);

    // 原始链表
    printf("原始链表：");
    printList(head->next);

    // 插入节点
    int x = 666;
    insertBeforeMax(head, x);

    // 插入后的链表
    printf("插入后的链表：");
    printList(head->next);

    // 释放链表内存
    freeList(head);

    return 0;
}
