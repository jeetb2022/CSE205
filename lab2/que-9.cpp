#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 void replatind(int array[],int position,int element){
    array[position-1]=element;
 }
int main()
{
    int arr[] = {1,3,5,7};
    cout<<"Initial array : ";
for (int i=0;i<4;i++){
    cout<<arr[i]<<" ";
}
replatind(arr,3,69);
    cout<<endl<<"Array after replacing : ";
for (int i=0;i<4;i++){
    cout<<arr[i]<<" ";
}


    return 0;
}