#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N];

void initialize(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = -1;
    }
    par[1] = 3;
    par[2] = 1;
    par[5] = 6;
    par[6] = 7;
}

// naive verson

// int find(int node) {
//     if (par[node] == -1) {
//         return node;
//     }
//     // Path compression
//     return par[node] = find(par[node]);
// }
int find(int node) {
    if (par[node] == -1) {
        return node;
    }
    // Path compression
    int leader =  find( par[node] );
    par[node] = leader; 
    return leader;
}

void dsu_union(int node1 , int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    par[leader1] = leader2;
}

int main() {
    initialize(8);
    cout << find(1) << endl;
    dsu_union(1,5);
    cout << find(1) << endl;
    
    return 0;
}
