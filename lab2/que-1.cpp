#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int srch(int arr[],int element,int size){
    for (int i=0;i<size;i++){
        if (arr[i]==element){
            return i+1;
        }
    }
    return -1;
}
int main()
{
    int array[] = {1,3,5,7,9};
int size = *(&array + 1) - array;
int ans = srch(array,5,size);
cout<<ans<<endl;
    return 0;
}