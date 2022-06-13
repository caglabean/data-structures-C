#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
} treenode;

treenode *createnode(int value)
{
    treenode *newnode = malloc(sizeof(treenode));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = value;

    return newnode;
}

void printTabs(int numtabs)
{
    for (int i = 0; i < numtabs; i++)
    {
        printf("\t");
    }
}
void printTree(treenode **root, int level)
{
    if ((*root) == NULL)
    {
        printf("-----<empty>-----\n");
        return;
    }
    // printTabs(level);
    printf("Value: %d\n", (*root)->data);

    printTabs(level);
    printf("Left ");
    printTree(&((*root)->left), level + 1);

    printTabs(level);
    printf("Right ");

    printTree(&((*root)->right), level + 1);
    printTabs(level - 1);
    printf("Done.\n");
}

int main()
{
    treenode *n1 = createnode(10);
    treenode *n2 = createnode(11);
    treenode *n3 = createnode(12);
    treenode *n4 = createnode(13);
    treenode *n5 = createnode(14);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    printTree(&n1, 1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    return 0;
}
