#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void push(node* &head, int val)
{
    node* temp = new node(val);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    temp->next=head;
    head = temp;
}

int top(node* head)
{
    if (head == NULL)
    {
        cout << "Stack is empty."<<endl;
        return -1;
    }
    return head->data;
}

void pop(node* &head)
{
    if(head==NULL)
    {
        cout<<"Stack is Empty."<<endl;
        return;
    }
    node* todelete=head;
    head=head->next;
    delete todelete;
}

bool isEmpty(node* head){
    if(head==NULL)
    return 1;
    return 0;
}

int postfixEvaluation(string s)
{
    // stack<int> st;
    node* head=NULL;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            push(head,s[i] - '0');
        }
        else
        {
            int op2 = top(head);
            pop(head);
            int op1 = top(head);
            pop(head);

            switch (s[i])
            {
            case '+':
                push(head,op1 + op2);
                break;

            case '-':
                push(head,op1 - op2);
                break;

            case '*':
                push(head,op1 * op2);
                break;

            case '/':
                push(head,op1 / op2);
                break;

            case '^':
                push(head,pow(op1, op2));
                break;
            }
        }
    }
    return top(head);
}

int main()
{
    cout << postfixEvaluation("46+2/5*7+") << endl;
}