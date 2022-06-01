#include <stdio.h>
#include <stdlib.h>

#define STOP -1

typedef struct node_s
{
    int data;
    struct node_s *next;
} node_t;

node_t *createList(void)
{
    node_t *head;
    int num;
    scanf("%d", &num);
    if (num == STOP)
    {
        head = NULL;
    }
    else
    {
        head = (node_t *)malloc(sizeof(node_t));
        head->data = num;
        head->next = createList();
    }
    return head;
}
void printList(node_t *headPtr)
{
    if (headPtr == NULL)
    {
        printf("\n");
    }
    else
    {
        printf("%d\n", headPtr->data);
        printList(headPtr->next);
    }
}

void deleteNode(node_t **headPtr, int target)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    node_t *prev = (node_t *)malloc(sizeof(node_t));
    temp = *headPtr;

    while (temp->data != target && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        prev->next = NULL;
        return;
    }
    prev->next = temp->next;
    free(temp);
}

int main()
{
    // node_t *root = (node_t *)malloc(sizeof(node_t));
    // root = createList();
    node_t *root, *middle, *last;
    root = (node_t *)malloc(sizeof(node_t));
    middle = (node_t *)malloc(sizeof(node_t));
    last = (node_t *)malloc(sizeof(node_t));
    root->data = 12;
    root->next = middle;
    middle->data = 43;
    middle->next = last;
    last->data = 87;
    last->next = NULL;

    printList(root);
    deleteNode(&root, 43);
    printList(root);

    free(root);
}