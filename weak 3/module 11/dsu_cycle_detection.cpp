#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int parent[N];
int group_size[N];

void initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

int dsu_find(int node)
{
    if (parent[node] == -1)
    {
        return node;
    }
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union_by_size(int node1 , int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);

    if (group_size[leader1] > group_size[leader2])
    {
        parent[leader2] = leader1;
        group_size[leader1] += leader2;
    }
    else
    {
        parent[leader1] = leader2;
        group_size[leader2] += leader1;
    }
}
int main()
{
    int n , e;
    cin >> n >> e;
    initialize(n);
    bool cycle = false;
    while (e--)
    {
        int a , b;
        cin >> a >> b;
        int leader1 = dsu_find(a);
        int leader2 = dsu_find(b);
        if (leader1 == leader2)
        {
            cycle = true;
        }
        else
        {
            dsu_union_by_size(a , b);
        }
    }
    if (cycle)
    {
        cout << "cycle detected! mother fucker" << endl;
    }
    else
    {
        cout << "Not detected " << endl;
    }
    return 0;
}