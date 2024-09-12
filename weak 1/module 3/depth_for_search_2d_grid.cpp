#include<bits/stdc++.h>
using namespace std;

int n , m;
char grid[20][20];
bool visited[20][20];
vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int i , int j)
{
    if (i < 0 || i>=n || j<0 || j>=m)
    {
        return false;
    }
    return true;
}


void bfs_grid(int srci,int srcj)
{
    cout << srci << " " << srcj << endl;
    visited[srci][srcj] = true;

    for(int i = 0; i< 4 ; i ++)
    {
        int childi= srci + v[i].first;
        int childj= srcj + v[i].second;

        if (valid(childi,childj) == true && visited[childi][childj] == false)
        {
            bfs_grid(childi,childj);
        }
        

        // cout << childi << " " << childj << endl;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
        
    }

    int srci , srcj;
    cin >> srci >> srcj ;

    memset(visited,false,sizeof(visited));

    bfs_grid(srci,srcj);



    // cout << srcj << " " << srcj << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << grid[i][j] ;
    //     }
    //     cout << endl;
    // }
    
    
    return 0;
}