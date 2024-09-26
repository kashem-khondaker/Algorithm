#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    cin >> n;
    int mart[n][n];
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            cin >> mart[i][j] ;
        }
    }
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mart[i][j] == 1 && i != j)
            {
                v.push_back({i , j});
            }
            
        }
        
    }

    for (pair<int,int> node :v )
    {
        cout << node.first << " " << node.second << endl;
    }
    
    
    return 0;
}