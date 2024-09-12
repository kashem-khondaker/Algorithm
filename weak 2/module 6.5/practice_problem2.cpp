#include <bits/stdc++.h>
using namespace std;

const int INF = 30000;

class Edge {
public:
    int u, v, c;
    Edge(int u, int v, int c) {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
// Adjusted to fit the problem constraints
const int N = 105; 
int dis[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Edge> EdgeList;
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }

    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
    }
    dis[1] = 0;

    // Relax edges n-1 times
    for (int i = 1; i < n; i++) {
        for (Edge ed : EdgeList) {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;

            if (dis[u] < INF && dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c;
            }
        }
    }

    // Output the distances
    for (int i = 1; i <= n; i++) {
        if (dis[i] == INF) {
            cout << 30000 << " ";
        } else {
            cout << dis[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
