#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// recursive
bool IsPalindrome(string s ,ll start, ll end){
    if (end>=start){

    if (end-start >1){
       return (IsPalindrome(s,start +1, end-1) && (s[end] == s[start]));
    }
    else if (end -start ==1){
        return (s[end] == s[start]);
    }
    else if (end==start){
        return (s[end] == s[start]);

    }
    }
}
int main()
{
    string s="abba";
    ll len = s.length();
     bool con = IsPalindrome(s,0,len);
  if (con == 0){
    
  cout<<"It is not a Palindrome"<<endl;
  }
  else {

  cout<<"It is a Palindrome"<<endl;
  }
ll left =0;
ll right=len-1;
ll flag=0;
while(left<=right){
if (s[left]!=s[right]){
    flag=1;
    break;
}
left++;
right--;
}
if (flag==1){
    cout<<"It is not a palindrome";
}
else {
    cout<<"It is a palindrome";

}

    return 0;
}