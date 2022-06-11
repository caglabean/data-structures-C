#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void countNodes(node *root)
{
    int count = 0;
    if (root == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    node *current = malloc(sizeof(node));
    current = root;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    printf("Num of nodes in the linked list: %d\n", count);
}

void printData(node *root)
{
    if (root == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    node *current = malloc(sizeof(node));
    current = root;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void addAtEnd(node *root, int data)
{
    node *current, *temp;
    current = malloc(sizeof(node));
    current = root;
    while (current->next != NULL)
    {
        current = current->next;
    }

    temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    current->next = temp;
}

node *addAtHeadByVal(node *root, int data)
{
    node *temp;
    temp = malloc(sizeof(node));

    temp->data = data;
    temp->next = NULL;

    temp->next = root;
    root = temp;
    return root;
}

void addAtHeadByRef(node **root, int data)
{
    node *temp = malloc(sizeof(node));

    temp->data = data;
    temp->next = NULL;

    temp->next = *root;
    *root = temp;
}

void addAtIndex(node **root, int data, int index)
{
    node *temp = malloc(sizeof(node));
    temp = *root;
    node *new = malloc(sizeof(node));
    new->data = data;
    new->next = NULL;

    if (index == 1)
    {
        new->next = *root;
        *root = new;
        return;
    }

    int count = 1;
    while (count != index - 1)
    {
        if (count >= index - 1)
        {
            temp->next = new;
            new->next = NULL;
            return;
        }
        count++;
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
}