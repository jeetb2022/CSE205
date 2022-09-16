#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Stack
{
    // Access specifier
public:
    struct stack
    {
        int data;
        struct stack *next;
    };

    stack *head = new stack();

    Stack(int element)
    {
        head->data = element;
        head->next = NULL;
    }

    void pushBack(int element){
    stack *temp = new stack();
    temp->data=element;
    temp->next=head;
    head = temp;
    }

    
    void top(){
    cout<< head->data<<endl;
    }


    void display(){

    stack *temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }


};

int main()
{
    Stack st(5);
    st.pushBack(69);
    st.display();
    st.top();
    return 0;
}