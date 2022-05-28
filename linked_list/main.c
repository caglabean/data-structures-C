#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    float num;
    char *name;
    struct node *next;
};

void printList_withLoop(struct node *head)
{
    while (head != NULL)
    {
        printf("%d->%f->%s\n", head->data, head->num, head->name);
        head = head->next;
    }
    if (head == NULL)
    {
        printf("NULL\n");
    }
}
void printList_withRecursive(struct node *head)
{
    if (head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d->%f->%s\n", head->data, head->num, head->name);
        printList_withRecursive(head->next);
    }
}
void insert_end(struct node **head, int val, float num, char *name_)
{
}
int main()
{
    struct node *head = NULL;
}