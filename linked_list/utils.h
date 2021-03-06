#ifndef _UTIL_H_
#define _UTIL_H_

typedef struct Node
{
    int data;          // data that is accessed by node pointer
    struct Node *next; // pointer to the next node
} node;

void countNodes(node *root);

void printData(node *root);

void addAtEnd(node *root, int data);

node *addAtHeadByVal(node *root, int data);

void addAtHeadByRef(node **root, int data);

void addAtIndex(node **root, int data, int index);

void deleteAtHead(node **root);

void deleteAtTail(node **root);

void deleteAtIndex(node **root, int index);

void reverseList(node **root);

int countNodesRecursive(node **root);

void deleteList(node **root);

#endif /* _UTIL_H_ */