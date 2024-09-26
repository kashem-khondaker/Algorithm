#include<bits/stdc++.h>
using namespace std;
class edge
{
    public:
    int u , v, w;
    edge(int u , int v , int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n;
    cin >>n;
    int mart[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mart[i][j];
        }
    }
    vector<edge> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mart[i][j] > 0 && i!=j)
            {
                v.push_back(edge(i , j , mart[i][j]));
            }
            
        }
        
    }
    

    for (edge edgelist :  v)
    {
        cout << edgelist.u << " " << edgelist.v << " "  << edgelist.w << endl;
    }
    
    return 0;
}