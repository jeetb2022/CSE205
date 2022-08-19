#include<iostream>
using namespace std;
#define ll long long int
void first();
void second();
void third();
void fourth();
void last();
void first(){
    second();
    cout<<"I am first"<<endl;
}
void second(){
    third();
    cout<<"I am second"<<endl;
}
void third(){
    fourth();
    cout<<"I am third"<<endl;
}
void fourth(){
    last();
    cout<<"I am fourth"<<endl;
}
void last(){
    cout<<"I am last"<<endl;
}
int main()
{
    first();
    return 0;
}