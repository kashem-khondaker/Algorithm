#include<bits/stdc++.h>
using namespace std;

class Edge
{
    public : 
    int u , v , c;
    Edge(int u , int v , int c)
    {
        this->u = u;
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
    vector<Edge>edglist;
    while (e--)
    {
        int u , v , c;
        cin >> u >> v >> c;
        edglist.push_back(Edge(u,v,c));
        // edglist.push_back(Edge(v,u,c));
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] =  INT_MAX;
    }
    // int src ;
    // cin >> src;
    dis[0] = 0; // jar teke amar distence ber korte hobe tar distance 0.


    int x = n -1;
    while (x--)
    {
        for (Edge ed: edglist )
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
    // some line chagne
    
    bool cycle = false;
    for (Edge edg: edglist )
    {
        int u = edg.u;
        int v = edg.v;
        int c = edg.c;

        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            cycle = true;
        }
    }
    
    if (cycle)
    {
        cout << "cycle found ! distance not possible ." << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " -> " <<  dis[i] << endl;
        } 
    }
    return 0;
}