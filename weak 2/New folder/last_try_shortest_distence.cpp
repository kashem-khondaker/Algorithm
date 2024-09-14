#include <bits/stdc++.h>

#define ll long long int
const ll INF = 1e18 + 5;
using namespace std;

int main() 
{
    ll n, e;
    cin >> n >> e;
    
    vector<vector<ll>> adj(n, vector<ll>(n, INF));
        
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adj[i][j] = 0;
            }
            else
            {
                adj[i][j] = INF;
            }
        }
    }
    
    while (e--) 
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--; 

        if (w < adj[a][b]) 
        {
            adj[a][b] = w;
        }  
    }
    
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    
    int t;
    cin >> t;
    while (t--) 
    {
        int x, y;
        cin >> x >> y;
        x--, y--; 
        
        if (adj[x][y] == INF) 
        {
            cout << -1 << endl;  
        } 
        else 
        {
            cout << adj[x][y] << endl;  
        }
    }
    
    return 0;
}
