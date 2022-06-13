#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    node *head = malloc(sizeof(node));
    node *current = malloc(sizeof(node));
    head->data = 23;
    current->data = 26;
    head->next = current;
    current = malloc(sizeof(node));
    current->data = 30;
    current->next = NULL;
    head->next->next = current;

    /* Count the nodes in the linked list */
    countNodes(head);

    /* Print the nodes in the linked list */
    printf("Nodes in the linked list: ");
    printData(head);

    /* Add a new node at the end of the linked list */
    printf("\nAdd node at the end, pass by val: ");
    addAtEnd(head, 42); // pass by value
    printData(head);

    /* Add a new node at the beginning of the linked list
       and update the head pointer */
    printf("Add node at the head, pass by val: ");
    head = addAtHeadByVal(head, 99); // pass by value
    printData(head);

    printf("Add node at the head, pass by ref: ");
    addAtHeadByRef(&head, 212); // pass by reference
    printData(head);

    /* Add a new node at a specified index of the linked list */
    printf("Add node at the index 2, pass by ref: ");
    addAtIndex(&head, 1881, 2);
    printData(head);
    printf("Add node at the index 8, pass by ref: ");
    addAtIndex(&head, 888, 8);
    printData(head);
    printf("Add node at the index 1, pass by ref: ");
    addAtIndex(&head, 1966, 1);
    printData(head);

    printf("\nDelete at head, by ref: ");
    deleteAtHead(&head);
    printData(head);

    printf("Delete at tail, by ref: ");
    deleteAtTail(&head);
    printData(head);

    printf("Delete at index 5, by ref: ");
    deleteAtIndex(&head, 5);
    printData(head);

    printf("Delete at index 6, by ref: ");
    deleteAtIndex(&head, 6);
    printData(head);

    printf("Delete at index 1, by ref: ");
    deleteAtIndex(&head, 1);
    printData(head);

    printf("\nReverse the list, by ref: ");
    reverseList(&head);
    printData(head);

    node *temp = malloc(sizeof(node));
    temp = head;
    printf("Number of nodes, using recursive: ");
    printf("%d\n", countNodesRecursive(&head));

    printf("\nDelete whole list, by ref: ");
    deleteList(&head);
    printData(head);
    printf("Number of nodes, using recursive: ");
    printf("%d\n", countNodesRecursive(&head));

    return 0;
}