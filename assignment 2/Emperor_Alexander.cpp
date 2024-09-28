#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll N = 1e5 + 5;
ll parent[N];
ll group_size[N];

class Edge 
{
    public:
    ll u, v, w;
    Edge(ll u, ll v, ll w) 
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b) 
{
    return a.w < b.w;
}

void dsu_initialize(ll n) 
{
    for (int i = 1; i <= n; i++) 
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

ll dsu_find(ll node)
{
    if (parent[node] == -1)
        return node;
    ll leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union_by_size(ll node1, ll node2) 
{
    ll leaderA = dsu_find(node1);
    ll leaderB = dsu_find(node2);

    if (leaderA != leaderB) 
    {
        
        if (group_size[leaderA] > group_size[leaderB]) 
        {
            parent[leaderB] = leaderA;
            group_size[leaderA] += group_size[leaderB];
        } 
        else 
        {
            parent[leaderA] = leaderB;
            group_size[leaderB] += group_size[leaderA];
        }
    }
}

int main() 
{
    ll n, e;
    cin >> n >> e;

    dsu_initialize(n);
    vector<Edge> edgeList;
    
    for (int i = 0; i < e; i++) 
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }
    
    
    sort(edgeList.begin(), edgeList.end(), cmp);

    ll totalCost = 0;
    ll totalEdge = 0;
    
    for (Edge ed : edgeList) 
    {
        ll leaderA = dsu_find(ed.u);
        ll leaderB = dsu_find(ed.v);
        
        if (leaderA != leaderB) 
        {
            dsu_union_by_size(ed.u, ed.v);
            totalCost += ed.w;
            totalEdge++;
        }
    }
    
    
    if (totalEdge != n - 1) 
    {
        cout << "Not Possible" << endl;
    } 
    else 
    {
        ll rode = e - totalEdge;
        cout << rode << " " << totalCost << endl;
    }
    
    return 0;
}
