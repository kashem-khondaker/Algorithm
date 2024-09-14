#include <bits/stdc++.h>
#define ll long long int

using namespace std;
const  int N = 1e5 + 5 ;
const ll INF = 1e18 + 5;
ll dis[N];

class Edge {
public:
    ll u, v, c;
    Edge( ll u,  ll v, ll c) 
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};


int main() 
{
    ll n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--) 
    {
        ll u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }

    for (int i = 0; i < n; i++) 
    {
        dis[i] = INF;
    }

    ll src;
    cin >> src;
    dis[src] = 0;

    for (int i = 1; i <= n - 1; i++) 
    {
        for (Edge ed : EdgeList) 
        {
            ll u = ed.u;
            ll v = ed.v;
            ll c = ed.c;
            
            if (dis[u] != INF && dis[u] + c < dis[v]) 
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    bool cycle = false;
    
    for (Edge ed : EdgeList) 
    {
        ll u = ed.u;
        ll v = ed.v;
        ll c = ed.c;
    
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
            ll D;
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
