#include<bits/stdc++.h>
using namespace std;

void convert(int n ,vector<int>V[])
{
    int mat[n][n];
    memset(mat, 0 , sizeof(mat));
    for (int i = 0; i < n; i++)
    {
        for(int j : V[i])
        {
            mat[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
}
int main()
{
    int n , e;
    cin >> n >> e;
    vector<int> V[n];
    while (e--)
    {
        int a , b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    convert(n , V);
    return 0;
}