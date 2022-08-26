#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void insatind(int arr[],int position,int element,int size){
    for (int i=size;i>=1;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=element;
}
int main()
{
    int n=5;
    int array[n] = {1,3,5,7,9};
int size = sizeof(array)/sizeof(array[0]);
insatind(array,3,69,size);
for(int i=0;i<size+1;i++){
    cout<<array[i]<<" ";
}
    return 0;
}