#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp)
    {
        temp->data = val;
        temp->next = NULL;
    }
    return temp;
}

/* This function inserts node at the head of linked list */
void push(Node **headRef, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "Null";
}
bool isPalindrome(Node *head)
{
    Node *temp = head;

    // Declare a Stack
    stack<int> s;

    // Push all the values of list into the stack
    while (temp)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    while (head != NULL)
    {

        // Get the top most element
        int val = s.top();

        // Pop the element
        s.pop();

        // Check is the data in the stack and list is same or not
        if (head->data != val)
        {
            return false;
        }

        // Move ahead
        head = head->next;
    }
    return true;
}
int main()
{
    Node *head = NULL;
    push(&head, 2);
    push(&head, 3);
    push(&head, 3);
    push(&head, 2);
    cout << "Original list :";
    printList(head);
    // function to Check list is Palindrome or not
    if (isPalindrome(head))
        cout << "\nGiven List is Palindrome";
    else
        cout << "\nGiven List is not Palindrome";
}
