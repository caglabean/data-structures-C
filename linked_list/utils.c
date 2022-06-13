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
void deleteAtHead(node **root)
{
    node *temp = malloc(sizeof(node));
    temp = *root;
    if (*root == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        (*root) = (*root)->next;
        free(temp);
        temp = NULL;
    }
}

void deleteAtTail(node **root)
{
    node *temp1 = malloc(sizeof(node));
    node *temp2 = malloc(sizeof(node));

    temp2 = *root;

    while (temp2->next != NULL)
    {
        temp1 = temp2;       // hold the second last node
        temp2 = temp2->next; // hold the last node
    }

    temp1->next = NULL; // make next of second last node NULL
    free(temp2);        // get rid of space allocated for last node
}

void deleteAtIndex(node **root, int index)
{
    node *temp1 = malloc(sizeof(node));
    node *temp2 = malloc(sizeof(node));

    temp1 = *root;

    if (index == 1)
    {
        (*root) = (*root)->next;
        free(temp1);
        temp1 = NULL;
        return;
    }
    // index--;
    while (index != 1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        index--;
    }
    if (temp1->next == NULL)
    {
        temp2->next = NULL;
        free(temp1);
        temp1 = NULL;
    }
    else
    {
        temp2->next = temp1->next;
        free(temp1);
        temp1 = NULL;
    }
}

void reverseList(node **root)
{
    node *prev = malloc(sizeof(node));
    node *current = malloc(sizeof(node));
    node *next = malloc(sizeof(node));
    prev = NULL;
    next = NULL;
    current = (*root);

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    (*root) = prev;
}

void deleteList(node **root)
{
    node *temp = malloc(sizeof(node));
    temp = *root;

    while (temp != NULL)
    {
        temp = temp->next;
        free(*root);
        *root = temp;
    }
}