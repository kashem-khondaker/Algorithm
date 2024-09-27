#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int par[N];
int sz[N];

void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        sz[i] = 1;
    }
}

int find(int node)
{
    if (par[node] == -1)
    {
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union_by_size(int node1 , int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (sz[leader1] > sz[leader2])
    {
        par[leader2] = leader1;
        sz[leader1] += leader2;
    }
    else
    {
        par[leader1] = leader2;
        sz[leader2] += leader1;
    }
    
}

int main()
{
    int n , e;
    cin >> n >> e;
    dsu_initialize(n);
    while (e--)
    {
        int a , b;
        cin >> a >> b;
        
        int leaderA = find(a);
        int leaderB = find(b);
        
        if (leaderA != leaderB)
        {
            dsu_union_by_size(a,b);
        }
    }
    
    vector<int> leader;
    
    for (int i = 1; i <= n; i++)
    {
        if (par[i] == -1)
        {
            leader.push_back(i);
        }    
    }
    
    cout << leader.size() - 1 << endl;

    for (int i = 0; i < leader.size() - 1; i++)
    {
        cout << leader[i] << " " << leader[i+1] << endl;
    }
    
    return 0;
}