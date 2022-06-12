#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int capacity;
    int *arr;
} Stack;

Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack)); // Allocate memo for the entire stack
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = (Stack *)malloc(sizeof(Stack) * capacity); // Allocate memo for members of stack array

    return stack;
}

int main()
{
}
