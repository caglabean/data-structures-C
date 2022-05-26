#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
/* Deletes the node specified with index n */
void deleteNode(Node **headPtr, int key)
{
    Node *prev = (Node *)malloc(sizeof(Node));
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = (*headPtr);
    prev = (*headPtr);
    if (temp->data == key) // if head is to be deleted
    {
        (*headPtr) = temp->next;
        return;
    }
    while (temp != NULL)
    {
        temp = temp->next;     // move temp ptr by 1 node
        if (temp->data == key) // if data pointed by temp ptr is to be deleted
        {
            if (temp->next == NULL) // if tail is to be deleted
            {
                prev->next = NULL;
                return;
            }
            prev->next = temp->next; // assign previous node to next of target node
            return;
        }
        prev = prev->next;
    }
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
int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 1881;
    head->next = NULL;
    // display(&head); // 1881
    addAtIndex(&head, 23, 2);
    // display(&head); // 1881 23
    addAtIndex(&head, 19, 1);
    // display(&head); // 19 1881 23
    addAtIndex(&head, 1923, 4);
    display(&head); // 19 1881 23 1923
    addAtIndex(&head, 42, 2);
    display(&head); // 19 42 1881 23 1923

    deleteNode(&head, 42); // 19 1881 23 1923
    display(&head);

    deleteNode(&head, 1923); // 19 1881 23
    display(&head);

    deleteNode(&head, 19); // 1881 23
    display(&head);

    free(head);
    return 0;
}