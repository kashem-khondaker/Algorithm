#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];

vector<int> bfs(int src, int l) 
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[src] = true;
    vector<int> val;

    while (!q.empty()) 
    {
        pair<int, int> p = q.front();
        q.pop();
        
        int par = p.first;
        int level = p.second;
        
        if (level == l) 
        {
            val.push_back(par);
        }
        
        for (int child : v[par]) 
        {
            if (!vis[child]) 
            {
                q.push({child, level + 1});
                vis[child] = true;
            }
        }
    }
    
    sort(val.begin(), val.end(), greater<int>());
    return val;
}

int main() 
{
    int n, e;
    cin >> n >> e;
    
    for (int i = 0; i < e; ++i) 
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l;
        cin >> l;
    
        memset(vis, false, sizeof(vis));
        vector<int> result = bfs(0, l);
    
        for (int node : result) 
        {
            cout << node << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
