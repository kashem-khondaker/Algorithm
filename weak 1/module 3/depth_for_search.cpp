#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5; // Max number of nodes
vector<int> v[N];      // Adjacency list to store graph
bool visited[N];       // Visited array to keep track of visited nodes

// Depth First Search function
void depth_first_search(int src) {
    cout << src << " "; // Print the current node
    visited[src] = true; // Mark the node as visited
    for (int child : v[src]) { // Explore all adjacent nodes
        if (!visited[child]) {
            depth_first_search(child); // Recursively visit unvisited nodes
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e; // Input number of nodes and edges

    // Input all the edges
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b); // Add edge a->b
        v[b].push_back(a); // Add edge b->a (undirected graph)
    }

    // Initialize all nodes as unvisited
    memset(visited, false, sizeof(visited));
    
    // Input the source node to start DFS from
    int src;
    cin >> src;

    // Start DFS from the given source
    depth_first_search(src);
    
    return 0;
}
