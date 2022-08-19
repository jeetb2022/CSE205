#include<iostream>
using namespace std;
#define ll long long int

// recursive 
 ll podArray(int a[],int n){
    static ll ans=1;
    if (n==0){
        return 1;
    }
    ans=a[n-1]*podArray(a,--n);
    return ans;
 }
int main()
{

    int a[4] = {2,2,3,5};
    ll ans3 =podArray(a,4);
cout<< "The product of the elements of array through recursive method is: "<< ans3<<endl;


ll sum=1;
    for (int i=0;i<4;i++){
        sum*=a[i];
    }
cout<< "The product of the elements of array through iterative method is: "<< sum<<endl;

    return 0;
}