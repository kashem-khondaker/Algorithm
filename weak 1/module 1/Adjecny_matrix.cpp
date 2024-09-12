#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , e;
    cin >> n >> e;

    int arr[n][n];
    memset(arr,0,sizeof(arr));// aita akta build in function jar dara amra kono array ka initialize korte pari . ...
    
    while (e--)
    {
        int a , b;
        
        cin >> a >> b ;

        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    if(arr[3][1]) {
        cout << "connected" << endl;
    }
    else {
        cout << "Not connected " << endl;
    }
    return 0;
}
