#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Queue
{
    // Access specifier
public:
    struct queue
    {
        int data;
        struct queue *next;
    };

    queue *head = new queue();

    Queue(int element)
    {
        head->data = element;
        head->next = NULL;
    }

    void pushBack(int element){
    queue *temp = new queue();
    temp->data=element;
    temp->next = NULL;
    head->next = temp;
    }

    
    int front(){
    return head->data;
    }


    void display(){

    queue *temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }


};

int main()
{
    Queue st(5);
    st.pushBack(69);
    st.display();
    int front_element = st.front();
    cout<<front_element<<endl;
    return 0;
}