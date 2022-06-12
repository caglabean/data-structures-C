#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

// node *top = NULL;

int main()
{
    int choice;
    char data, popped;

    do
    {
        printf("1: Push to the stack\n2: Pop top elemet from stack\n3: Print stack\n0: Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter character to push: ");
            scanf(" %c", &data);
            push(data);
            break;
        case 2:
            if ((popped = pop()) != '0')
                printf("Popped top: %c\n", popped);
            break;
        case 3:
            printStack();
            break;
        case 0:
            break;
        default:
            printf("You have entered invalid character.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}