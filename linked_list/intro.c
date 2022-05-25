#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void displayLinkedList(struct Node *head)
{
    struct Node *aux = head;
    while (aux != NULL)
    {
        if (aux->link == NULL)
        {
            printf("%d\n", aux->data);
        }
        else
        {
            printf("%d -> ", aux->data);
        }

        aux = aux->link;
    }
    printf("\n");
}
/* Inserts a new node from the head of linked list */
void push(struct Node **pointerToHeadPtr, int val)
{
    /* Initialize the new node to be added */
    struct Node *aux = (struct Node *)malloc(sizeof(struct Node));
    /* Assign value to new node */
    aux->data = val;
    /* Make new node next pointer as head pointer */
    aux->link = *pointerToHeadPtr;
    /* Make head pointer point to the new node data */
    (*pointerToHeadPtr) = aux;
}
void insert(struct Node **pointerToHeadPtr, int n, int val)
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = val;  // new node to hold the val
    temp1->link = NULL; // initially points to NULL

    if (n == 1) // If data is inserted from the head
    {
        temp1->link = *pointerToHeadPtr;
        *pointerToHeadPtr = temp1;
    }
    else
    {
        struct Node *temp2 = (struct Node *)malloc(sizeof(struct Node));
        temp2 = *pointerToHeadPtr;
        for (int i = 0; i < n - 2; i++)
        {
            temp2 = temp2->link; // Assign node ptr to ptr to the next node to traverse the list
        }
        if (temp2->link == NULL)
        {
            temp1->link = NULL;
            temp2->link = temp1;
        }
        else
        {
            temp1->link = temp2->link;
            temp2->link = temp1;
        }
    }
}
int main()
{
    struct Node *head = NULL;                          // head pointer to node
    struct Node *temp;                                 // pointer to node
    temp = (struct Node *)malloc(sizeof(struct Node)); // Allocate enough memory for temp pointer to node
    (*temp).data = 42;                                 // *temp points to a node with data=42
    (*temp).link = NULL;                               // first and last node points to NULL
    head = temp;                                       // head pointer holds the address of first node i.e the value of temp pointer

    /* Simply print the linked list */
    printf("\nInitialized linked list:\n");
    printf("------------------------\n");
    displayLinkedList(head);

    /* Insert new node from the head */
    printf("Inserting new node from the head:\n");
    printf("---------------------------------\n");
    int value, n;
    printf("Number of values to be inserted from head: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Data: ");
        scanf("%d", &value);
        push(&head, value); // by reference
        displayLinkedList(head);
    }

    /* Insert new node from some index between head and tail */
    printf("Inserting new node from n. position:\n");
    printf("---------------------------------\n");
    insert(&head, 2, 818); //  420 -> 818 -> 69 -> 33 -> 42
    displayLinkedList(head);
    insert(&head, 1, 64); // 64 -> 420 -> 818 -> 69 -> 33 -> 42
    displayLinkedList(head);
    insert(&head, 5, 1); // 64 -> 420 -> 818 -> 69 -> 1 -> 33 -> 42
    displayLinkedList(head);

    /* Insert new node from the tail */
    printf("Inserting new node from the tail:\n");
    printf("---------------------------------\n");
    insert(&head, 8, 0); // 64 -> 420 -> 818 -> 69 -> 1 -> 33 -> 42 -> 0
    displayLinkedList(head);

    /* Delete a node and print the linked list */

    // displayLinkedList(head);

    free(head);

    return 0;
}