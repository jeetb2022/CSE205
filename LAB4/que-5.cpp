#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int priority;
    Node *next;

    Node(int x, int y)
    {
        data = x;
        priority = y;
        next = NULL;
    }
};

class priorityQueue
{
public:
    Node *head;
    priorityQueue()
    {
        head = NULL;
    }

    int peek()
    {
        return head->data;
    }

    void pop()
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void push(int x, int y)
    {
        Node *t = head;
        Node *temp = new Node(x, y);
        // cout << temp->data << endl;
        if (head == NULL)
        {
            head = temp;
        }
        else if (head->priority < y && head != NULL)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            while (t->next != NULL && t->next->priority > y)
                t = t->next;
            temp->next = t->next;
            t->next = temp;
        }
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }
};

int main()
{
    priorityQueue pq;
    cout << pq.isEmpty() << endl;
    pq.push(3, 2);
    pq.push(8, 0);
    pq.push(7, 7);
    pq.push(5, 5);
    while (!pq.isEmpty())
    {
        cout << pq.peek() << " ";
        pq.pop();
    }
}