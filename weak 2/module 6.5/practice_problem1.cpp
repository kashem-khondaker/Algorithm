#include <bits/stdc++.h>
#define ll long long 
#define INF INT_MAX
using namespace std;

void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) 
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    cin >> n >> e;

    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
            if (dist[i][j] == -1) {
                dist[i][j] = INF;
            }
        }
    }

    floydWarshall(dist, n);

    int maxShortestDist = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] != INF && dist[i][j] > maxShortestDist) {
                maxShortestDist = dist[i][j];
            }
        }
    }

    cout << maxShortestDist << endl;

    return 0;
}
