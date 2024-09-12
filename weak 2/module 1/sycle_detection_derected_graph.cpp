#include<bits/stdc++.h>
using namespace std;

vector<int> v[50];
bool visited[50];
bool path_visited[50];
bool ans = false;

void dfs(int parent)
{
    visited[parent] = true;
    path_visited[parent] = true;

    for (int child : v[parent])
    {
        if (path_visited[child])
        {
            ans = true;
        }
        
        if (visited[child] == false)
        {
            dfs(child);
            path_visited[parent] = false;
        }
        
    }
    
}

int main()
{
    int n , e;
    cin >> n >> e;
    while (e--)
    {
        int a , b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    memset(visited,false, sizeof(visited));
    memset(path_visited,false, sizeof(path_visited));

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            dfs(i);
        }
        
    }

    if (ans)
    {
        cout << "cycle detected ";
    }
    else
    {
        cout << "cycle not detected";
    }
    
    
    return 0;
}