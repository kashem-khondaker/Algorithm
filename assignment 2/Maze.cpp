#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int n, m;
char mart[N][N];
bool vis[N][N];
map<pair<int, int>, pair<int, int>> par;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; 

bool valid(int ci, int cj) 
{
    return (ci >= 0 && ci < n && cj >= 0 && cj < m);
}

void bfs(int si, int sj) 
{
    vis[si][sj] = true;
    queue<pair<int, int>> q;
    q.push({si, sj});

    while (!q.empty()) 
    {
        pair<int, int> node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ci = node.first + d[i].first;
            int cj = node.second + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && mart[ci][cj] != '#') 
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
                par[{ci, cj}] = {node.first, node.second}; 
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int si, sj, di, dj;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> mart[i][j];
            if (mart[i][j] == 'R') 
            {
                si = i;
                sj = j;
            }
            if (mart[i][j] == 'D') 
            {
                di = i;
                dj = j;
            }
        }
    }

   
    if (si == di && sj == dj) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                cout << mart[i][j];
            }
            cout << endl;
        }
        return 0; 
        
    }

    memset(vis, false, sizeof(vis));

    bfs(si, sj);

    if (vis[di][dj]) 
    {
        
        int xi = di;
        int xj = dj;

        
        while (true) 
        {
            if (mart[xi][xj] == 'R') 
            {
                break;
            }

            if (mart[xi][xj] != 'D') 
            {
                mart[xi][xj] = 'X';
            }

            
            if (par.find({xi, xj}) == par.end()) 
            {
                break; 
            }

            int newxi = par[{xi, xj}].first;  
            int newxj = par[{xi, xj}].second;

            xi = newxi;  
            xj = newxj;  
        }
    }

    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cout << mart[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
