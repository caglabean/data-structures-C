#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STOP -1

typedef struct node_s
{
    char name[30];
    int age;
    struct node_s *next;
} node_t;
void printList(node_t *headPtr)
{
    if (headPtr == NULL)
    {
        printf("\n");
    }
    else
    {
        printf("%s - %d\n", headPtr->name, headPtr->age);
        printList(headPtr->next);
    }
}

node_t *getList(void)
{
    int data;
    node_t *nodePtr;

    printf("Enter -1 to stop adding new nodes.\nAge: ");
    scanf("%d", &data);

    if (data == STOP)
    {
        nodePtr == NULL;
    }
    else
    {
        nodePtr = (node_t *)malloc(sizeof(node_t));
        nodePtr->age = data;
        printf("Name: ");
        scanf("%s", nodePtr->name);
        nodePtr->next = getList();
    }
    return nodePtr;
}

node_t *searchNode(node_t *headPtr, int target)
{
    /* Returns: pointer to target data if found,
                NULL if target is not found */
    node_t *i;
    for (i = headPtr; i != NULL && i->age != target; i = i->next)
    {
    }
    return i;
}

int main()
{
    node_t *list, *found;
    list = getList();

    printList(list);
    found = searchNode(list, 52);
    if (found != NULL)
    {
        printf("%s -> %d\n", found->name, found->age);
    }
    else
    {
        printf("Data does not exist.\n");
    }

    return 0;
}