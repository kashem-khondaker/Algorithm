#include<bits/stdc++.h>
using namespace std;

vector<int> v[1001];
bool visited[1001];
int level[10];
int arr[10];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    
    visited[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        cout << parent << endl;

        for(int child : v[parent])
        {
            if(visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
                level[child] = level[parent] + 1;

                arr[child] = parent;
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

    int src , destination;
    cin >> src >> destination;

    memset(visited,false,sizeof(visited));
    memset(level,-1,sizeof(level));
    memset(arr,-1,sizeof(arr));

    bfs(src);

    cout << endl << endl;
    cout << "level print" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "- level - " << level[i] << endl;
    }

    cout << endl << endl << "path printing " << endl;

    int x = destination ;
    vector<int> path;
    while (x != -1)
    {
        path.push_back(x);
        x = arr[x];
    }
    reverse(path.begin(),path.end());

    for (int val : path)
    {
        cout << val << endl ;
    }
    
    
    
    return 0;
}