#include <bits/stdc++.h>
#define ll long long int

using namespace std;
const  int N = 1e5 ;
const ll INF = 1e18;
ll dis[N];

class Edge {
public:
    int u, v, c;
    Edge( int u,  int v, int c) 
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};


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
        dis[i] = INF;
    }

    long long int src;
    cin >> src;
    dis[src] = 0;

    for (int i = 1; i <= n - 1; i++) 
    {
        for (Edge ed : EdgeList) 
        {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            
            if (dis[u] != INF && dis[u] + c < dis[v]) 
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    bool cycle = false;
    
    for (Edge ed : EdgeList) 
    {
        int u = ed.u;
        int v = ed.v;
        int c = ed.c;
    
        if (dis[u] != INF && dis[u] + c < dis[v]) 
        {
            cycle = true;
            break;
        }
    }

    if (cycle) 
    {
        cout << "Negative Cycle Detected" << endl;
        // break;
            return 0;
    } 
    else
    {
        int t;
        cin >> t;
        while (t--) 
        {
            int D;
            cin >> D;
    
            if (dis[D] == INF) 
            {
                cout << "Not Possible" << endl;
            } 
            else 
            {
                cout << dis[D] << endl;
            }
        }
    }
    

    return 0;
}
