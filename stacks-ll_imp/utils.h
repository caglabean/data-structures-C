#ifndef _UTIL_H_
#define _UTIL_H_

typedef struct Node
{
    char data;
    struct Node *next;
} node;

void push(char data);

char pop();

void printStack();

#endif /* _UTIL_H_ */