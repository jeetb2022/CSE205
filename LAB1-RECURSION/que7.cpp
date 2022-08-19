#include<iostream>
using namespace std;
#define ll long long int

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
int main()
{
      string s3="hello";
      string ans,s4;
  s4 = reverse(s3,0);
    cout<<"The reversed string  through recursive method  is : "<<s4<<endl;

    for (int i =0;i<s3.length();i++){
        ans.push_back(s3[s3.length()-1-i]);
    }
    cout<<"The reversed string through iterative method is : "<<ans<<endl;

    return 0;
}