#include <stdio.h>

#define MAX 101
int arr[MAX];
int top = -1;

void push(int *arr, int n)
{
    arr[++top]; // preincrement op used to increment before asignment
}

int main()
{
    int num_nodes, new;
    printf("Num nodes: ");
    scanf("%d", &num_nodes);

    for (int i = 0; i < num_nodes; i++)
    {

        printf("Node %d: ", i + 1);
        scanf("%d", &new);
        if (i != num_nodes - 1)
        {
            printf("%d -> ", arr[top]);
        }
        else
        {
            printf("%d\n", arr[top]);
        }
    }
    return 0;
}