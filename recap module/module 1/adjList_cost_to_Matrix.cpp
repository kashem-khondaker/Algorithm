#include<bits/stdc++.h>
using namespace std;

void convert(int n ,vector<pair<int,int>> adjlist[])
{
    int mart[n][n];
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            mart[i][j] = 0;
            if (i==j)
            {
                mart[i][j] = -1;
            }
            
        }
    }

    for (int i = 0; i < n; i++)
    {
        for(pair<int,int> node : adjlist[i])
        {
            int b = node.first;
            int w = node.second;
            mart[i][b]= w; 
        }
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mart[i][j] << " ";
        }
        cout << endl;
    }
    
    
}

int main()
{
    int n , e;
    cin >> n >> e;
    vector<pair<int,int>> adjlist[n];
    while (e--)
    {
        int a , b , w;
        cin >> a >> b >> w;
        adjlist[a].push_back({b,w});
    }
    convert(n , adjlist);
    return 0;
}