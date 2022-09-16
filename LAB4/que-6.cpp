#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev, *next;
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

class Deque
{
public:
    Node *front;
    Node *back;
    int Size;

    Deque()
    {
        front = NULL;
        back = NULL;
        Size = 0;
    }

    bool isEmpty()
    {
        if (front == NULL)
            return true;
        return false;
    }

    int size()
    {
        return Size;
    }

    void insertAtfront(int data)
    {
        Node *temp = new Node(data);
        if (front == NULL)
        {
            front = temp;
            back = front;
        }
        else
        {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
        Size++;
    }

    void insertAtback(int data)
    {
        Node *temp = new Node(data);
        if (back == NULL)
        {
            back = temp;
            front = back;
        }
        else
        {
            temp->prev = back;
            back->next = temp;
            back = temp;
        }

        Size++;
    }

    void deleteFront()
    {
        if (isEmpty())
            cout << "Queue is empty\n";

        else
        {
            Node *temp = front;
            front = front->next;

            if (front == NULL)
                back = NULL;
            else
                front->prev = NULL;
            free(temp);

            Size--;
        }
    }

    void deleteBack()
    {

        if (isEmpty())
            cout << "Queue is empty\n";

        else
        {
            Node *temp = back;
            back = back->prev;

            if (back == NULL)
                front = NULL;
            else
                back->next = NULL;
            free(temp);

            Size--;
        }
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return front->data;
    }

    int getBack()
    {
        if (isEmpty())
            return -1;
        return back->data;
    }

    void erase()
    {
        back = NULL;
        while (front != NULL)
        {
            Node *temp = front;
            front = front->next;
            free(temp);
        }
        Size = 0;
    }
};

int main()
{
    Deque dq;
    dq.insertAtback(69);
    dq.insertAtback(93);
    cout << "Rear end element: "<< dq.getBack() << endl;
    dq.deleteBack();
    dq.insertAtfront(15);
    cout << "Front end element: "<< dq.getFront() << endl;
    cout << "Number of elements in Deque: "<< dq.size() << endl;
    dq.deleteFront();
    dq.erase();
    cout<<dq.isEmpty()<<endl;
}