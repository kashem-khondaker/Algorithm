#include<bits/stdc++.h>
using namespace std;

vector<int> v[20];
bool visited[20];
vector<int> val;

int dfs(int src)
{
    visited[src] = true;
    int cnt = 1;

    for (int child : v[src])
    {
        if (visited[child] == false)
        {
            cnt += dfs(child);
        }
        
    }
    return cnt;

}

int main()
{
    int n ,e;
    cin >> n >> e;
    while (e--)
    {
        int a , b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(visited,false,sizeof(visited));
    

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            val.push_back(dfs(i));
        }
        
    }

    
    
    sort(val.begin(),val.end());

    for (int i : val)
    {
        cout << i << " ";
    }
    
    return 0;
}