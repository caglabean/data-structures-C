#ifndef _UTIL_H_
#define _UTIL_H_

typedef struct Stack
{
    int top;
    int capacity;
    int *arr;
} Stack;

Stack *createStack(int capacity);

int isEmpty(Stack *stack);

int isFull(Stack *stack);

void push(int data, Stack *stack);

int pop(Stack *stack);

void peek(Stack *stack);

#endif /* _UTIL_H_ */