#include<bits/stdc++.h>
using namespace std;

vector<int> v[10];
bool visited[10];
int distance_[10];

void sortest_distance(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    distance_[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child : v[parent])
        {
            if (visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
                distance_[child] = distance_[parent] + 1;
            }
            
        }
        
    }
    
}

int main()
{
    int n , e;
    cin >> n >> e;

    while (e--)
    {
        int a , b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    int q;
    cin >> q;
    while (q--)
    {
        int src , distination;
        cin >> src >> distination;

        memset(visited,false,sizeof(visited));
        memset(distance_,-1,sizeof(distance_));

        sortest_distance(src);

        cout << distance_[distination] << endl;
    }
    return 0;
}