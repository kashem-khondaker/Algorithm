#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];

int n, m;

int dx[4] = {-1, 0, 1, 0}; // row er move
int dy[4] = {0, 1, 0, -1}; // col er move

bool valid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m && (graph[i][j] != '-' ))
    {
        return true;
    }    
    return false;
}

void bfs(int si, int sj)
{

    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        int nrow = node.first;
        int ncol = node.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = nrow + dx[i]; // children er row
            int cj = ncol + dy[i]; // children er column

            if (valid(ci, cj) && vis[ci][cj] == false)
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
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
            cin >> graph[i][j];
        }
    }

    int src_row , src_clm;
    int des_row , des_clm;
    cin >> src_row >> src_clm >> des_row >> des_clm ;

    

    // cout << src_row << " " << src_clm << endl;
    // cout << des_row << " " << des_clm << endl;

    bfs(src_row,src_clm);

    if ( vis[des_row][des_clm] )
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    
    return 0;
}