#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int parent[N];
int group_size[N];

int cmp , mx ;

void initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
    cmp = n;
    mx = INT_MIN;
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
    if (leader1 == leader2)
    {
        return ;
    }
    
    if (group_size[leader1] > group_size[leader2])
    {
        parent[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
        mx = max(mx , group_size[leader1]);
    }
    else
    {
        parent[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
        mx = max(mx , group_size[leader2]);
    }
    cmp --;
}


int main()
{
    int n , e;
    cin >> n >> e;

    initialize(n);
    
    while (e--)
    {
        int a , b;
        cin >> a >> b;
        dsu_union_by_size(a, b);
        cout << cmp << " " << mx << endl;
    }
    
    return 0;
}