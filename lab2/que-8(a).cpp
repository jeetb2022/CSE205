
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct Node
{
    int data;
    struct Node *next;
};

void linsatbeg(Node *&head, int newElement)
{
    Node *newNode = new Node();
    newNode->data = newElement;
    newNode->next = head;
    head = newNode;
}

int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    linsatbeg(head, 69);
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}