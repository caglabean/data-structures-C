#include <stdbool.h>
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
    treenode *newnode = (treenode *)malloc(sizeof(treenode));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = value;

    return newnode;
}

void insertNode(treenode **root, int value)
{
    if ((*root) == NULL)
    {
        (*root) = createnode(value); // create new node if tree empty
        return;
    }

    if ((*root)->data >= value) // if value<=node->data, add new node to left
    {
        insertNode((&(*root)->left), value);
        return;
    }
    if ((*root)->data < value) // if value>node->data, add new node to right
    {
        insertNode(&((*root)->right), value);
        return;
    }
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

bool searchTree(treenode *root, int value)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == value)
    {
        return true;
    }

    if (value > root->data)
    {
        return searchTree(root->right, value);
    }
    else
    {
        return searchTree(root->left, value);
    }
}
bool isFound(treenode *root, int toFind)
{
    bool isFound = searchTree(root, toFind);
    if (isFound == 1)
    {
        printf("%d is found.\n", toFind);
        return true;
    }
    else
    {
        printf("%d is NOT found.\n", toFind);
        return false;
    }
}

int main()
{
    treenode *root = NULL; // initially tree empty
    insertNode(&root, 25);
    insertNode(&root, 11);
    insertNode(&root, 9);
    insertNode(&root, 4);
    insertNode(&root, 12);
    insertNode(&root, 14);
    insertNode(&root, 21);

    printTree(&root, 1);

    int toFind;
    isFound(root, 1);
    isFound(root, 12);
    isFound(root, 25);
    isFound(root, 67);
    isFound(root, 4);

    return 0;
}
