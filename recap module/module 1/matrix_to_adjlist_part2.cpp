#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin >> n;
    int mart[n][n];
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> mart[i][j];
        }
    }

    vector<pair<int,int>> adjlist[n];

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            if ( ( mart[i][j] > 0 && mart[i][j] != 1 ))
            {
                adjlist[i].push_back({j,mart[i][j]});
            }
            
        }
    }


    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " ;
        for(pair<int,int> node : adjlist[i])
        {
            cout << "{" << node.first << "," << node.second << "}" << " ";
        }
        cout << endl;
    }
    
    
    
    return 0;
}