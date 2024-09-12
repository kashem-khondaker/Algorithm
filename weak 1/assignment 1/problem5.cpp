#include <bits/stdc++.h>
using namespace std;

const int N = 1005; 
vector<string> matrix(N);
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

int dfs(int x, int y) 
{
    vis[x][y] = true;
    int count = 1; 
    
    for (int i = 0; i < 4; i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (valid(nx, ny)) 
        {
            count += dfs(nx, ny); 
        }
    }
    return count;
}

int main() 
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) 
    {
        cin >> matrix[i];
    }
    
    memset(vis, false, sizeof(vis));
    
    vector<int> v;
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (valid(i, j)) 
            {
                int n = dfs(i, j);
                v.push_back(n);
            }
        }
    }
    
    if (v.empty())
    {
        cout << "0" << endl;
    }
    else
    {
        sort(v.begin(), v.end());
        for (int i : v) 
        {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}
