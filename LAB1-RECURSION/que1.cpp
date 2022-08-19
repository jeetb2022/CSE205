#include<iostream>
using namespace std;
#define ll long long int

// Recursive 

 ll addUp(ll n){
    if (n==1){
        return 1;
    }
    // cout<<n<<" ";
    ll ans = n+addUp(n-1);
    return ans;
 }



int main()
{
ll n =5;

ll ans =addUp(n);
cout<<" The addition of the numbers is : "<<ans;
ll sum=0;
    for (int i=0;i<n;i++){
        sum+=i+1;
    }
cout<<" The addition of the numbers is : "<<sum;
    return 0;
}
