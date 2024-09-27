#include<bits/stdc++.h>
#define ll long long int
#define pr pair<ll,ll>
using namespace std;

const int N = 1e5+5;
vector<pr> v[N];
ll dis[N];
ll par[N];

class cmp {
    public:
    bool operator()(pr a , pr b) {
        return a.second > b.second;
    }
};

void dijkstra(int s) {
    priority_queue<pr , vector<pr> , cmp> pq;
    pq.push({s,0});
    dis[s] = 0;
    while (!pq.empty()) {
        pr parent = pq.top();
        pq.pop();
        ll node = parent.first;
        ll cost = parent.second;
        for(pr child : v[node]) {
            ll childNode = child.first;
            ll childCost = child.second;

            if (cost + childCost < dis[childNode]) {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
                par[childNode] = node;
            }
        }
    }
}

int main() {
    
    ll n , e;
    cin >> n >> e;
    
    while (e--) {
        ll a , b , c;
        cin >> a >> b >> c;  
        v[a].push_back({b,c});
        v[b].push_back({a,c}); 
    }
    for (int i = 1; i <= n; i++) 
    {  
        dis[i] = 1e18;
        par[i] = -1;
    }
    
    dijkstra(1);

    int x = n;  
    vector<int> path;
    
    while (x != -1) {
        path.push_back(x);
        x = par[x];
    }
    reverse(path.begin(), path.end());
    for (int  i : path)
    {
        cout << i << " ";
    }
    
    
    return 0;
}
