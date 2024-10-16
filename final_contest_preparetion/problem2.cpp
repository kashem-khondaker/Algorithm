#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long int ll;
ll input;
ll dp[N];

bool rec(ll n)
{
    if(n > input)
        return false;
    if(n == input)
        return true;

    if(dp[n] != -1) 
        return dp[n];

    
    return dp[n] = rec(n+3) || rec(n*2);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> input;
        memset(dp, -1, sizeof(dp)); 
        bool flag = rec(1);
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}