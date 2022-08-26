
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int flag = 0;
void dubbly_remove(Node *&head, int element)
{
    Node *temp = head;
        while (temp->next!=NULL)
        {
            if (temp->data == element){
                break;
            }
            temp = temp->next;
        }
        if (temp->prev == NULL){
        temp->next->prev = NULL;
        head = temp->next;
        }
        else if (temp->next == NULL){

        temp->prev->next = temp->next;
        }
        else {

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
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
    head->data = 4;
    head->next = second;
    head->prev = NULL;
    second->data = 50;
    second->next = third;
    second->prev = head;
    third->data = 3;
    third->next = NULL;
    third->prev = second;

    dubbly_remove(head,3);
    if (flag == 0)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    return 0;
}