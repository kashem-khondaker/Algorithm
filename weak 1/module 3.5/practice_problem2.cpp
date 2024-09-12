#include<bits/stdc++.h>
using namespace std;

vector<int> v[20];
bool visited[20];

void dfs(int src)
{
    visited[src] = true;
    
    for (int child : v[src])
    {
        if (visited[child] == false)
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(visited,false,sizeof(visited));

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            dfs(i);
            cnt ++;
        }
    }

    cout << cnt << endl;
    return 0;
}