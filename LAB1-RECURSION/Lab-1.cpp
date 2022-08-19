#include <bits/stdc++.h>
using namespace std;
#define ll long long int

 ll addUp(ll n){
    if (n==1){
        return 1;
    }
    // cout<<n<<" ";
    ll ans = n+addUp(n-1);
    return ans;
 }
 ll fib(ll n){
    if (n==1){
        return 0;
    }
    if (n==2){
        return 1;
    }
    ll ans = fib(n-1) +fib(n-2);
    return ans;
 }
 ll podArray(int a[],int n){
    static ll ans=1;
    if (n==0){
        return 1;
    }
    ans=a[n-1]*podArray(a,--n);
    return ans;
 }
 string s1;
string reverse(string s,ll i){
  if (i==s.length()-1){
    // cout<<s[i];
    s1.push_back(s[i]);
    return s1;
  }
  reverse( s,i+1);
  s1.push_back(s[i]);
  // cout<<s[i];
  return s1 ;

}
bool IsPalindrome(string s ,ll start, ll end){
    if (end>=start){

    if (end-start >1){
       return (IsPalindrome(s,start +1, end-1) && s[end] == s[start]);
    }
    else if (end -start ==1){
        return (s[end] == s[start]);
    }
    else if (end==start){
        return (s[end] == s[start]);

    }
    }
}

int gcd(int a,int b){
    if (a%b==0){ 
        return b;
    }
 return gcd(b,a%b);
}


int main()
{
ll n =5;
int a[4] = {2,2,3,5};
ll ans =addUp(n);
ll ans2 =fib(n);
ll ans3 =podArray(a,4);
cout<<ans3<<endl;;
 
  string s3;
  s3 = reverse("onbo",0);
  bool con = IsPalindrome("anwa",0,3);
  if (con == 0){
    
  cout<<"It is not a Palindrome"<<endl;
  }
  else {

  cout<<"It is a Palindrome"<<endl;
  }
  cout<<"The reversed string is :"<<s3<<endl;;


   int a1,b;
   a1=18;
   b=12;
int GCD=gcd(15,24);
    cout<<"The GCD of the two numbers is "<<GCD<<endl;
    return 0;
}