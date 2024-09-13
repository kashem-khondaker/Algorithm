#include <bits/stdc++.h>
using namespace std;

const  long long int N = 1e5+5;
vector<pair<long long int, long long int>> v[N];
long long int dis[N];

class cmp 
{
public:
    bool operator()(pair<long long int, long long int> a, pair<long long int, long long int> b) 
    {
        return a.second > b.second;
    }
};

void dijkstra(long long int src) 
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, cmp> pq;
    
    pq.push({src, 0});
    dis[src] = 0;
    
    while (!pq.empty()) 
    {
        pair<long long int, long long int> parent = pq.top();
        pq.pop();
        long long int parent_node = parent.first;
        long long int parent_cost = parent.second;
    
        for (pair<long long int, long long int> child : v[parent_node]) 
        {
            long long int childNode = child.first;
            long long int childCost = child.second;
    
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
    long long int n, e;
    cin >> n >> e;
    while (e--) 
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    for (long long int i = 1; i <= n; i++) 
    {
        dis[i] =  INT_MAX;
    }

    long long int src, q;
    cin >> src >> q;
    
    dijkstra(src);

    while (q--) 
    {
        long long int D, DW;
        cin >> D >> DW;

        if (dis[D] <= DW) 
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
