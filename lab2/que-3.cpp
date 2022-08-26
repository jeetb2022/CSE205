#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void srch(int arr[],int position,int size){
    for (int i=position-1;i<size;i++){
        arr[i]=arr[i+1];
    }
}
int main()
{
    int n=5;
    int array[n] = {1,3,5,7,9};
int size = sizeof(array)/sizeof(array[0]);
srch(array,5,size);
for(int i=0;i<size-1;i++){
    cout<<array[i]<<" ";
}
    return 0;
}