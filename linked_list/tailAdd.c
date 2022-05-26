#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

void insertNode(Node **head, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(1);
    }

    Node *curr = *head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
    new_node->val = value;
    new_node->next = NULL;
}
/* Traverses the linked list and prints the nodes */
void displayList(Node **head)
{
    Node *curr = (Node *)malloc(sizeof(Node));
    curr = *head;
    while (curr != NULL)
    {
        if (curr->next != NULL)
        {
            printf("%d -> ", curr->val);
        }
        else
        {
            printf("%d\n", curr->val);
        }
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    Node *head;
    head = (Node *)malloc(sizeof(Node));
    head->val = 1999;
    head->next = NULL;
    displayList(&head);
    insertNode(&head, 1881);
    displayList(&head);
    insertNode(&head, 1966);
    displayList(&head);
    insertNode(&head, 1991);
    // for (Node *curr = head; curr != NULL; curr = curr->next)
    // {
    //     printf("%d  ", curr->val);
    // }
    // printf("\n");
    displayList(&head);
    return 0;
}