#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// Recursive code 

ll fib(ll n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    ll ans = fib(n - 1) + fib(n - 2);
    return ans;
}

int main()
{

    ll n = 5;

    ll ans = fib(n);
    cout << " The number through recursive method  is : " << ans;
    ll sum = 0;

    // Iterative code 
    vector<ll> ans1(n);
    ans1[0] = 0;
    ans1[1] = 1;
    for (int i = 2; i < n; i++)
    {
        ans1[i] = ans1[i - 1] + ans1[i - 2];
    }
    cout << endl;
    cout << " The number through iterative method is : " << ans1[n - 1];
    return 0;
}