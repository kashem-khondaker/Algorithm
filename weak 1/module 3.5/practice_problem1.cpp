#include <bits/stdc++.h>
using namespace std;



vector<int> v[20];
bool visited[20];



int dfs(int src) 
{
    visited[src] = true;
    int count = 1; 

    for (int child : v[src]) 
    {
        if (visited[child] == false) 
        {
            count += dfs(child); 
        }
    }
    return count;
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

    memset(visited, false, sizeof(visited));

    int start;
    cin >> start;

    int count_nodes = dfs(start);
    cout << count_nodes << endl;

    return 0;
}
