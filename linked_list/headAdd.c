#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

/* Inserts a new node at the head */
void push(Node **head, int val)
{
    Node *curr = (Node *)malloc(sizeof(Node));

    curr->data = val;
    curr->next = *head;
    *head = curr;
}

/* Traverses the linked list and prints the nodes */
void displayList(Node **head)
{
    Node *curr = (Node *)malloc(sizeof(Node));
    curr = *head;
    printf("\n");

    while (curr != NULL)
    {
        if (curr->next != NULL)
        {
            printf("%d -> ", curr->data);
        }
        else
        {
            printf("%d\n", curr->data);
        }

        curr = curr->next;
    }
}
int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 42;
    head->next = NULL;
    displayList(&head);
    push(&head, 999);
    displayList(&head);
}
