#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// recursive
int gcd(int a,int b){
    if (a%b==0){ 
        return b;
    }
 return gcd(b,a%b);
}



int main()
{

   ll a1,b;
   a1=18;
   b=12;
ll GCD=gcd(a1,b);
    cout<<"The GCD of the two numbers through recursive method  is "<<GCD<<endl;

    // iterative
    while(a1%b!=0){
        ll temp=a1;
        a1=b;
        b=temp%b;

    }
    cout<<"The GCD of the two numbers through iterative method is: "<<GCD<<endl;
    return 0;
}