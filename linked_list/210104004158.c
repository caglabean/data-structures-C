#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int year;
    char bookname[30];
    char author[30];
    struct node *next;
};
struct node *insert_node(struct node *root, char *bookname, char *author, int year)
{
    // Sort according to string into the node struct.
    // It's name is "name".
    // You will sort ascending order.
    struct node *new = malloc(sizeof(struct node));
    strcpy(new->author, author);
    strcpy(new->bookname, bookname);
    new->year = year;

    new->next = NULL;

    struct node *temp = malloc(sizeof(struct node)); // ptr to move head ptr
    temp = root;

    // If node is added at the head, move next of head ptr to address of new node
    if (root == NULL)
    {
        new->next = root;
        root = new;
        return root;
    }

    if (temp->next != NULL)
    {
        new->next = temp->next; // Assign next of new node to address of node at n.index
        temp->next = new;       // Assign next of previos node to address of new node
    }
    else
    {
        temp->next = new; // Assign next of previos node to address of new node
        new->next = NULL;
    }

    // if (root == NULL)
    // {
    //     root = root->next;
    // }
    // else
    // {
    //     struct node *temp;
    //     while (root != NULL)
    //     {
    //         if (root->year > root->next->year)
    //         {
    //             temp = root;
    //             root = root->next;
    //             root->next = temp;
    //             return root;
    //         }
    //         else
    //         {
    //             root = root->next;
    //         }
    //     }
    // }
    return root;
}

struct node *read_file()
{
    struct node *temp = malloc(sizeof(struct node));
    temp->next = NULL;
    FILE *fp;
    fp = fopen("source.txt", "r");

    char name[30], aut[30];
    int y;
    // read until end of file
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %d", name, aut, &y);
        // printf("%s %s %d\n", name, aut, y);
        insert_node(temp, name, aut, y);
    }
    return temp;
}
void print_nodes(struct node *root)
{
    while (root != NULL)
    {
        printf("%s  %s  %d\n", root->bookname, root->author, root->year);
        root = root->next; // move to the next row
    }
}
struct node *delete_node(struct node *root, char *bookname)
{
    int check = 0;
    struct node *prev = malloc(sizeof(struct node));
    struct node *temp = malloc(sizeof(struct node));
    temp = (root);
    prev = (root);
    if (strcmp(temp->bookname, bookname) == 0) // if head is to be deleted
    {
        check = 1;
        root = temp->next;
        return root;
    }
    while (temp != NULL)
    {
        temp = temp->next;                         // move temp ptr by 1 node
        if (strcmp(temp->bookname, bookname) == 0) // if data pointed by temp ptr is to be deleted
        {
            check = 1;
            if (temp->next == NULL) // if tail is to be deleted
            {
                prev->next = NULL;
                return root;
            }
            prev->next = temp->next; // assign previous node to next of target node
            return root;
        }

        if (temp->next == NULL && check == 0)
        {
            printf("%s is not in the list.\n", bookname);
            return NULL;
        }
        prev = prev->next;
    }

    return root;
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->next = NULL;
    printf("Reading the source.txt file...\n");
    head = read_file();
    printf("Printing the linked list...\n\n");
    print_nodes(head);

    char deleted[30];
    printf("\nWhich book do you want to delete? ");
    scanf("%s", deleted);
    printf("\nPrinting the linked list...\n\n");
    delete_node(head, deleted);
    print_nodes(head);
}