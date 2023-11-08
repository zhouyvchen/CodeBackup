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

struct ListNode* createLinkedList(int arr[], int size) {
    struct ListNode* head = NULL;
    for (int i = 0; i < size; i++) {
        struct ListNode* newNode = createNode(arr[i]);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

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

// 将链表按基准划分
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* smallerHead = NULL; // 存放小于基准值的节点链表的头节点
    struct ListNode* smallerTail = NULL; // 存放小于基准值的节点链表的尾节点
    struct ListNode* greaterHead = NULL; // 存放大于等于基准值的节点链表的头节点
    struct ListNode* greaterTail = NULL; // 存放大于等于基准值的节点链表的尾节点

    while (head != NULL) {
        struct ListNode* newNode = createNode(head->val);
        if (head->val < x) {
            // 将小于基准值的节点连接到smaller链表
            if (smallerHead == NULL) {
                smallerHead = newNode;
                smallerTail = newNode;
            } else {
                smallerTail->next = newNode;
                smallerTail = smallerTail->next;
            }
        } else {
            // 将大于等于基准值的节点连接到greater链表
            if (greaterHead == NULL) {
                greaterHead = newNode;
                greaterTail = newNode;
            } else {
                greaterTail->next = newNode;
                greaterTail = greaterTail->next;
            }
        }
        head = head->next;
    }

    // 将smaller链表和greater链表连接起来
    if (smallerTail != NULL) {
        smallerTail->next = greaterHead;
        return smallerHead;
    } else {
        return greaterHead;
    }
}

int main() {
    struct ListNode* head = createNode(2);
    head->next = createNode(1);
    head->next->next = createNode(5);
    head->next->next->next = createNode(6);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(3);

    printf("原来的单链表");
    printList(head);

    int x = 5;
    struct ListNode* newHead = partition(head, x);

    printf("分划后的单链表");
    printList(newHead);

    freeList(newHead);

    return 0;
}
