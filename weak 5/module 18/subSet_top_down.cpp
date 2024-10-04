#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
bool subSet_sum(int n , int s , int ar[])
{
    if (n==0)
    {
        return (s==0);
    }
    if (dp[n][s] != -1)
    {
        return dp[n][s];
    }
    
    if (n <= s)
    {
        bool op1 = subSet_sum(n-1,s-ar[n-1],ar);
        bool op2 = subSet_sum(n-1,s,ar);
        return dp[n][s] = op1 || op2;
    }
    else
    {
        return dp[n][s] = subSet_sum(n-1,s,ar);
    }
    
}
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int sum;
    cin >> sum;
    memset(dp,-1,sizeof(dp));
    if (subSet_sum(n,sum,ar))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    return 0;
}