#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const int N = 1e5 + 5;
int dis[N];

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    int src , q;
    cin >> src >> q;
    
    while(q--)
    {
        int D , DW;
        cin >> D >> DW;
        dis[src] = 0;
        for(int i = 1; i <= n - 1 ; i++)
        {
            for(Edge ed : EdgeList)
            {
                int u = ed.u;
                int v = ed.v;
                int c = ed.c;
                
                if( dis[u] < INT_MAX && dis[u] + c < dis[v])
                {
                    dis[v] = dis[u] + c;
                }
                
            }
        }
        if(dis[D] <= DW)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
    }
    
    return 0;
}