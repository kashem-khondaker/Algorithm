#include<bits/stdc++.h>
using namespace std;

vector<int> v[1001];
bool visited[1001];

void bfs_traversat_with_pair(int src , int destination)
{
    queue<pair<int,int> > q;
    q.push({src,0});

    while (!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        
        int parent = p.first;
        int level = p.second;

        if (parent == destination)
        {
            cout << level << endl;
        }
        

        for (int child : v[parent])
        {
            if (visited[child] == false)
            {
                q.push( {child, level + 1} );
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

    memset( visited,false,sizeof(visited) );

    int destination;
    cin >> destination;

    bfs_traversat_with_pair(src ,destination);
    return 0;
}