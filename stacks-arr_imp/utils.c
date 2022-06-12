#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack)); // Allocate memo for the entire stack
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = malloc(sizeof(stack->arr) * capacity); // Allocate memo for members of stack array

    printf("Stack with capacity %d has been created.\n", capacity);

    return stack;
}

int isEmpty(Stack *stack)
{
    return (stack->top == -1);
}

int isFull(Stack *stack)
{
    return (stack->top == (stack->capacity) - 1);
}

void push(int data, Stack *stack)
{
    if (isFull(stack) == 1)
    {
        printf("Stack is full!\n");
        return;
    }
    printf("%d is pushed to the stack.\n", data);
    stack->arr[++stack->top] = data;
    return;
}

int pop(Stack *stack)
{
    if (isEmpty(stack) == 1)
    {
        printf("Stack is empty!\n");
        return 0;
    }
    return stack->arr[stack->top--];
}

void peek(Stack *stack)
{
    if (isEmpty(stack) == 1)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", stack->arr[stack->top]);
}