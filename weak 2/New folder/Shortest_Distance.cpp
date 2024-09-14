#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 1e5+5;
const long long int INF = 1e18+5;

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

vector<Edge> edges;
ll dis[N];

void bellman_ford(ll src, ll n) 
{
    for (int i = 0; i < n + 5; i++) 
    {
        dis[i] = INF;
    }
    dis[src] = 0;

    for (int i = 0; i < n - 1; i++) 
    {
        for (const auto& edge : edges) 
        {
            if (dis[edge.u] != INF && dis[edge.u] + edge.c < dis[edge.v]) 
            {
                dis[edge.v] = dis[edge.u] + edge.c;
            }
        }
    }
}

int main() 
{
    ll n, e;
    cin >> n >> e;

    while (e--) 
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }

    int q;
    cin >> q;

    while (q--) 
    {
        int src, dest;
        cin >> src >> dest;

        bellman_ford(src, n);

        if (dis[dest] == INF) 
        {
            cout << "-1" << endl;  
        } 
        else 
        {
            cout << dis[dest] << endl;  
        }
    }

    return 0;
}
