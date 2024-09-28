#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int n , m;
char mart[N][N];
bool vis[N][N];
int ans;

vector<pair<int,int> > d = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int ci , int cj)
{
    return (ci >= 0 && ci < n && cj >= 0 && cj < m);
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    ans++;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) && !vis[ci][cj] && mart[ci][cj] != '-')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for(int j =0 ; j < m ; j++)
        {
            cin >> mart[i][j] ;
        }
    } 

    memset(vis, false, sizeof(vis));
    int mn = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && mart[i][j] == '.')
            {
                ans = 0;
                dfs(i, j);
                mn = min(mn, ans);
            }
        }
    }

    if (mn == INT_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << mn << endl;
    }
    
    return 0;
}