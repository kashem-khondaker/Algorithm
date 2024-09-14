#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 1e5+5;
const long long int INF = 1e18+5;
vector<pair<ll, ll>> v[N];
ll dis[N];

class cmp 
{
public:
    bool operator()(pair<ll, ll> a, pair<ll, ll> b) 
    {
        return a.second > b.second;
    }
};


void dijkstra(ll src) 
{
    
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty()) 
    {
        pair<ll, ll> parent = pq.top();
        pq.pop();
        
        ll parent_node = parent.first;
        ll parent_cost = parent.second;

        
        if (parent_cost > dis[parent_node]) 
        {
            continue;
        }

       
        for (pair<ll, ll> child : v[parent_node]) 
        {
            ll childNode = child.first;
            ll childCost = child.second;

           
            if (parent_cost + childCost < dis[childNode]) 
            {
                dis[childNode] = parent_cost + childCost;
                pq.push({childNode, dis[childNode]});
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
        v[a].push_back({b, c});
    }

    int q;
    cin >> q;

    while (q--) 
    {
        int src, dest;
        cin >> src >> dest;

        
        for (int i = 1; i <= n; i++) 
        {
            dis[i] = INF;
        }

        
        dijkstra(src);

        
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
