#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll fac (ll n){
     
    if (n==0){
        return 1;

    }
    ll ans=(n)*fac(n-1);
    return ans;

}
int main(){
//  fac(4);
float n;
cin>>n;
ll m = (ll)n;
if ( m!=n || n<0){
    cout<<"pls enter a valid number ";
}
else {

cout<<"The factorial through recursive method is: "<<fac(n)<<endl;;
}
ll ans=1;
while(n>0){
    ans*=n;
    n--;
}
cout<<"The factorial through iterative method is: "<<ans;
}