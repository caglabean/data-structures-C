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

#endif /* _UTIL_H_ */