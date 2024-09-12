#include<bits/stdc++.h>
using namespace std;

vector<int> v[1001];
bool visited[1001];

void bfs(int src)
{
    
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        cout << parent << endl;

        // for (int i = 0; i < v[parent].size() ; i++)
        // {
        //     cout << v[parent][i] << endl;
        // }

        // for (int i = 0; i < v[parent].size() ; i++)
        // {
        //     if (visited [ v[parent][i] ]  == false)
        //     {
        //         q.push(v[parent][i]);
        //         visited[v[parent][i]] = true;
        //     }
            
        // }
        
        
        for(int child : v[parent])
        {
            if(visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
            }
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
        v[b].push_back(a);
    }

    int src;
    cin >> src;

    memset(visited,false,sizeof(visited));

    bfs(src);
    return 0;
}