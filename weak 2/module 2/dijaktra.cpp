#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<pair<int,int>> adjlist[N];
int dis[N];

void dijkstra(int src)
{
    queue<pair<int,int>> q;
    q.push({src,0});
    dis[src] = 0;
    while (!q.empty())
    {
        pair<int,int> parent = q.front();
        q.pop();

        int parent_node = parent.first;
        int parent_cost = parent.second;

        for (pair<int,int> child :  adjlist[parent_node])
        {
            int child_node = child.first;
            int child_cost = child.second;

            if (parent_cost + child_cost > dis[child_node])
            {
                // path relax 
                dis[child_node] = parent_cost + child_cost ;
                q.push({child_node, dis[child_node]});
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
        int a , b , c;
        cin >> a >> b >> c;
        adjlist[a].push_back({b,c});
        adjlist[b].push_back({a,c});
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }
    
    return 0;
}