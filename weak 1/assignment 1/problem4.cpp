#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
char matrix[N][N];
bool vis[N][N];
int n, m;

int dx[4] = {0, 0, 1, -1}; 
int dy[4] = {1, -1, 0, 0}; 

bool valid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m && matrix[i][j] == '.' && vis[i][j]==false)
    {
        return true;
    }    
    return false;
}

void dfs(int x, int y) 
{
    vis[x][y] = true;
    
    for (int i = 0; i < 4; i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (valid(nx, ny)) 
        {
            dfs(nx, ny);
        }
    }
}

int main() 
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) 
    {
        cin >> matrix[i];
    }
    
    memset(vis, false, sizeof(vis));
    
    int c = 0;
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (valid(i, j)) 
            {
                dfs(i, j);
                c++;
            }
        }
    }
    cout << c << endl;
    return 0;
}
