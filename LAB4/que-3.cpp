#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    char data;
    node* next;

    node(char val)
    {
        data = val;
        next = NULL;
    }
};

void push(node *&head, char val)
{
    node *temp = new node(val);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

char top(node *head)
{
    if (head == NULL)
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return head->data;
}

void pop(node *&head)
{
    if (head == NULL)
    {
        cout << "Stack is Empty." << endl;
        return;
    }
    node *todelete = head;
    head = head->next;
    delete todelete;
}

bool isEmpty(node *head)
{
    if (head == NULL)
        return 1;
    return 0;
}

bool balancedParanthesis(node* &head,string s)
{
    // stack <char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            push(head, s[i]);
        else
        {
            if (s[i] == ')')
            {
                if (top(head) == '(')
                    pop(head);
                else
                    return false;
            }
            if (s[i] == '}')
            {
                if (top(head) == '{')
                    pop(head);
                else
                    return false;
            }
            else if (s[i] == ']')
            {
                if (top(head) == '[')
                    pop(head);
                else
                    return false;
            }
        }
    }
    if(isEmpty(head))
    return true;
    else
    return false;
}

int main()
{
    node *head = NULL;
    string s ;
    cin>>s;
    if(balancedParanthesis(head,s))
    cout<<"Valid String"<<endl;
    else
    cout<<"Invalid String"<<endl;
}