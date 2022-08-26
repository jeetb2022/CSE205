
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct Node
{
    int data;
    struct Node *next;
};

void delatend(Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (temp->next->next == NULL)
        {
            temp->next = NULL;
        }
    }
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

    delatend(head);
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}