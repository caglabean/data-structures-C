/* Stack: Array based implementation */

#include <stdio.h>

#define MAX 101
int arr[MAX];
int top = -1; // initially stack is empty

void push(int n)
{
    if (top == MAX - 1)
    {
        printf("Error! Stack overflow\n");
        return;
    }
    arr[++top] = n; // preincrement op is used to increment before asignment
}
void pop()
{
    if (top == -1)
    {
        printf("Error! Underflow\n");
        return;
    }
    top--;
}
int getTop()
{
    return arr[top];
}
void print()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{

    push(5);
    print();
    push(88);
    print();
    push(999);
    print();
    pop();
    print();
    push(12);
    print();
    return 0;
}