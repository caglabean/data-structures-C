#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void display(Node **headPtr)
{
    Node *curr = (Node *)malloc(sizeof(Node));
    curr = (*headPtr);
    while (curr != NULL)
    {
        if (curr->next == NULL)
        {
            printf("%d\n", curr->data);
        }
        else
        {
            printf("%d -> ", curr->data);
        }
        curr = curr->next;
    }
    free(curr);
}
void addAtIndex(Node **headPtr, int value, int n)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = value;
    new->next = NULL;

    Node *temp = (Node *)malloc(sizeof(Node)); // ptr to move head ptr
    temp = *headPtr;

    // If node is added at the head, move next of head ptr to address of new node
    if (n == 1)
    {
        new->next = (*headPtr);
        (*headPtr) = new;
        return;
    }
    /* Iterate over linked list until (n-1). node */
    for (int i = 0; i < n - 2; i++)
    {
        temp = temp->next;
    }
    if (temp->next != NULL)
    {
        new->next = temp->next; // Assign next of new node to address of node at n.index
        temp->next = new;       // Assign next of previos node to address of new node
    }
    else
    {
        temp->next = new; // Assign next of previos node to address of new node
        new->next = NULL;
    }
}

int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 42;
    head->next = NULL;
    display(&head); // 42
    addAtIndex(&head, 1881, 2);
    display(&head); // 42 1881
    addAtIndex(&head, 7, 1);
    display(&head); // 7 42 1881
    addAtIndex(&head, 149, 2);
    display(&head); // 7 149 42 1881
    addAtIndex(&head, 1923, 5);
    display(&head); // 7 149 42 1881 1923

    free(head);
    return 0;
}