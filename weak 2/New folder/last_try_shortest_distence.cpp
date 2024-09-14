#include <bits/stdc++.h>

#define ll long long int
const ll INF = 1e18 + 5;
using namespace std;

int main() 
{
    ll n, e;
    cin >> n >> e;
    
    ll adj[n + 1][n + 1]; // Use n + 1 to handle 1-based indexing
        
    // Initialize the adjacency matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
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
    
    // Read edges
    while (e--) 
    {
        int a, b, w;
        cin >> a >> b >> w;

        if (w < adj[a][b]) 
        {
            adj[a][b] = w;
        }  
    }
    
    // Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] < INF && adj[k][j] < INF && adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    // Answer queries
    int t;
    cin >> t;
    while (t--) 
    {
        int x, y;
        cin >> x >> y;
        
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
