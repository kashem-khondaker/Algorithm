#include<bits/stdc++.h>
using namespace std;

class Edge
{
    public:
    int u, v , c;
    Edge(int u , int v , int c)
    {
        this->u = u ;
        this->v = v;
        this->c = c;
    }
};

const int N = 1e5;
int dis[N];

int main()
{
    int n , e;
    cin >> n >> e;
    vector<Edge> edglist;
    while (e--)
    {
        int u , v , c;
        cin >> u >> v >> c;
        edglist.push_back(Edge(u,v,c));
    }

    for (Edge ed : edglist )
    {
        cout << ed.u << " " << ed.v << " " << ed.c << endl;
    }
    cout << endl << endl;
    for (int i = 0; i < n; i++)
    {
        dis[i] =  INT_MAX;
    }

    int x = n - 1;
    dis[0] = 0;

    while (x--)
    {
        for (Edge ed : edglist )
        {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;

            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
           
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }
    
    
    return 0;
}