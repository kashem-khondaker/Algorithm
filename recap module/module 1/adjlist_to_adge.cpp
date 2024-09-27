#include<bits/stdc++.h>
using namespace std;

class edge
{
    public:
    int u , v , w;
    edge(int u , int v , int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n , e;
    cin >> n >> e;
    vector<pair<int,int>> v[n];
    while (e--)
    {
        int a , b , c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for(pair<int,int> p : v[i])
        {
            cout << "{" << p.first << "," << p.second << "} " ;
        }
        cout << endl;
    }
    

    // edge create from adjlist;

    vector<edge> edgelist;
    for (int i = 0; i < n; i++)
    {
        for(pair<int,int> node : v[i])
        {
            edgelist.push_back(edge(i,node.first , node.second));
        }
    }
    
    for (edge ed :  edgelist)
    {
        cout << ed.u << " " << ed.v << " "  << ed.w << endl;
    }
    
    
    return 0;
}