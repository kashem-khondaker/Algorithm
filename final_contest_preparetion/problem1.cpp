#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int dparr[N][N];

int dp(int n,int weight[] , int value[],int w)
{
    if (n < 0 || w == 0)
    {
        return 0;
    }

    if (dparr[n][w] != -1)
    {
        return dparr[n][w];
    }
    
    
    if (weight[n] <= w)
    {
        // choice 2 ta 
        int option1 = value[n] + dp(n-1,weight,value,w - weight[n]);
        int option2 = dp(n-1,weight,value,w);
        
        return dparr[n][w] = max(option1,option2);
    }
    else
    {
        return dparr[n][w] = dp(n-1,weight,value,w);
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n , w;
        cin >> n >> w;
        int weight[n];
        int value[n];
        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }
        
        for (int i = 0; i < n; i++)
        {
            cin >> value[i];
        }
        memset(dparr,-1,sizeof(dparr));

        cout << dp(n-1,weight,value,w) << endl; 
        
    }
    
    return 0;
}