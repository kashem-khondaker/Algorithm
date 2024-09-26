#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , e;
    cin >> n >> e;
    int mart[n][n];
    for (int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            // mart[i][j] = 0;
            // if (i == j)
            // {
            //     mart[i][j] = 1;
            // }/////////////////////////
            
            mart[i][j] = -1;
            if (i == j)
            {
                mart[i][j] = 0;
            }
            
            
        }
    }

    while (e--)
    {
        // int a , b;
        // cin >> a >> b;
        // mart[a][b] = 1;
        // mart[b][a] = 1;////////////////////////////////
        
        int a , b , w;
        cin >> a >> b >> w;
        mart[a][b] = w;
        mart[b][a] = w;
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mart[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}