#include <bits/stdc++.h>
using namespace std;


int n, m;
char a[20][20];
bool visited[20][20];
int distanc[20][20];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};


bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    return true;
}


void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    
    visited[si][sj] = true;
    distanc[si][sj] = 0;
    
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        int a = parent.first, b = parent.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int childi = a + d[i].first;
            int childj = b + d[i].second;
            
            if (valid(childi, childj) == true && visited[childi][childj] == false)
            {
                q.push({childi, childj});
                
                visited[childi][childj] = true;
                distanc[childi][childj] = distanc[a][b] + 1;
            }
        }
    }
}



int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    
    int si, sj;
    cin >> si >> sj;
    
    memset(visited, false, sizeof(visited));
    memset(distanc, -1, sizeof(distanc));
    
    bfs(si, sj);
    
    cout << distanc[2][3];
    
    
    return 0;
}