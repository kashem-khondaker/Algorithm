#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin >> n;
    int mart[n][n];
    for (int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> mart[i][j];
        }
    }

    vector<int> adjlist[n];
    for (int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if (mart[i][j] == 1)
            {
                adjlist[i].push_back(j);
            }
            
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int child : adjlist[i])
        {
            cout << child << " ";
        }
        cout << endl;
    }
    
    
    
    return 0;
}