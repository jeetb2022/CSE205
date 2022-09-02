#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void insatend(int arr[],int element,int size){
    arr[size]=element;
}
int main()
{
    int n=5;
    int array[n] = {1,3,5,7,9};
int size = sizeof(array)/sizeof(array[0]);
insatend(array,69,size);
for(int i=0;i<size+1;i++){
    cout<<array[i]<<" ";
}
    return 0;
}