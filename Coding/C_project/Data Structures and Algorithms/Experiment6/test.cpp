#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
struct ListNode {
    int val;
    struct ListNode *next;
};

// �����½ڵ�
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

// ��ӡ����
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// ��������׼����
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* smallerHead = NULL; // ���С�ڻ�׼ֵ�Ľڵ������ͷ�ڵ�
    struct ListNode* smallerTail = NULL; // ���С�ڻ�׼ֵ�Ľڵ������β�ڵ�
    struct ListNode* greaterHead = NULL; // ��Ŵ��ڵ��ڻ�׼ֵ�Ľڵ������ͷ�ڵ�
    struct ListNode* greaterTail = NULL; // ��Ŵ��ڵ��ڻ�׼ֵ�Ľڵ������β�ڵ�

    while (head != NULL) {
        struct ListNode* newNode = createNode(head->val);
        if (head->val < x) {
            // ��С�ڻ�׼ֵ�Ľڵ����ӵ�smaller����
            if (smallerHead == NULL) {
                smallerHead = newNode;
                smallerTail = newNode;
            } else {
                smallerTail->next = newNode;
                smallerTail = smallerTail->next;
            }
        } else {
            // �����ڵ��ڻ�׼ֵ�Ľڵ����ӵ�greater����
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

    // ��smaller�����greater������������
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

    printf("ԭ���ĵ�����");
    printList(head);

    int x = 5;
    struct ListNode* newHead = partition(head, x);

    printf("�ֻ���ĵ�����");
    printList(newHead);

    freeList(newHead);

    return 0;
}
