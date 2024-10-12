#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];

int unbounded_knapsack(int n, int w, int val[], int wight[]) 
{
    if (n == 0 || w == 0) 
    {
        return 0;
    }
    if (dp[n][w] != -1) 
    {
        return dp[n][w];
    }

    if (wight[n - 1] <= w) 
    {
        
        int op1 = val[n - 1] + unbounded_knapsack(n, w - wight[n - 1], val, wight);
        int op2 = unbounded_knapsack(n - 1, w, val, wight);
        return dp[n][w] = max(op1, op2);
    } 
    else 
    {
        return dp[n][w] = unbounded_knapsack(n - 1, w, val, wight);
    }
}

int main()
{
    int n;
    cin >> n;
    int val[n] ,  wight[n];
    for (int i = 0; i < n; i++)
    {
        cin>> val[i];
        wight[i] = i+1;
    }
    memset(dp,-1,sizeof(dp));
    cout << unbounded_knapsack(n,n,val,wight);
    
    return 0;
}