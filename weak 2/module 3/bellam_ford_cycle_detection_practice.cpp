#include<bits/stdc++.h>
using namespace std;

class Edge
{
    public:
    int u , v , c;
    Edge(int a ,int b ,int c)
    {
        u = a ; v = b ; this->c = c;
    }
};
const int N = 1e5;
int distence_[N];
int main()
{
    int n , e;
    cin >> n >> e;
    vector<Edge> edglist;
    while (e--)
    {
        int u , v , c;
        cin >> u >> v >> c;
        edglist.push_back(Edge(u,v,c));
    }
    for (int i = 0; i < n; i++)
    {
        distence_[i] = INT_MAX;
    }
    distence_[0] = 0;

    int x = n-1;
    while (x--)
    {
        for (Edge ed: edglist )
        {
            if (distence_[ed.u] < INT_MAX && distence_[ed.u] + ed.c < distence_[ed.v])
            {
                distence_[ed.v] = distence_[ed.u] + ed.c;
            }
            
        }
        
    }
    bool cycle = false;
    for (Edge ed : edglist )
    {
        if (distence_[ed.u] < INT_MAX && distence_[ed.u] + ed.c < distence_[ed.v])
        {
            cycle = true;
        }
        
    }
    if (cycle)
    {
        cout << "cycle detected .. sortest path impossible .." << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << distence_[i] << endl; 
        }
    }
    
    return 0;
}