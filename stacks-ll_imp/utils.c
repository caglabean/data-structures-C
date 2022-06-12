#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

node *top = NULL;

void push(char data)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Stack overflow!\n");
        return;
    }

    new->data = data;
    new->next = NULL;

    new->next = top;

    top = new; // set new node the new top
}

char pop()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
        return '0';
    }
    node *temp = (node *)malloc(sizeof(node));
    temp = top;
    top = top->next; // set the next of top node the new top

    char popped = temp->data; // data in popped top
    free(temp);               // free the old top node

    return popped;
}

void printStack()
{
    node *temp = top;

    if (temp == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    while (temp) // while top != NULL
    {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n**************\n");
}