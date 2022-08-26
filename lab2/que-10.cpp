
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct Node
{
    int data;
    struct Node *next;
};

int flag = 0;
void replatind(Node *&head,int position,int element)
{
    Node *temp = head;
    Node *temp2 = head;
    int i=1;
    int size=1;
    while (temp2->next!=NULL)
    {
        temp2 = temp2->next;
        size++;
    }
    if (position > size){
        cout<<"-1";
        flag++;
    }
    else {
        
    while (i!=position)
    {
        temp = temp->next;
        i++;
    }
    temp->data = element;
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

    replatind(head,5,69);
    if (flag==0){

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    }
    return 0;
}