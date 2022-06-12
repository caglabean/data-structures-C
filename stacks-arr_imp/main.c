#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int popped;
    Stack *stack = createStack(4);

    if ((popped = pop(stack)) != 0)
        printf("Popped element: %d\n", popped);
    push(42, stack);
    peek(stack);
    push(56, stack);
    push(33, stack);
    peek(stack);
    if ((popped = pop(stack)) != 0)
        printf("Popped element: %d\n", popped);
    peek(stack);
    push(99, stack);
    peek(stack);
    push(588, stack);
    push(23, stack);
}
