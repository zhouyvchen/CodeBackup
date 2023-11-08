#include "stdio.h"

typedef int E;

struct LinkNode {
    E element;
    struct LinkNode *next;
};

typedef struct LinkNode *Node;

void initLink(Node node) {
    node->next = NULL;
}

bool insertList(Node node, E element, int index){

}