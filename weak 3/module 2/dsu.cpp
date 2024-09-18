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
    int leader =  find(par[node]);
    par[node] = leader; 
    return leader;
}

int main() {
    initialize(5);
    cout << find(0) << endl; // Output: 0
    cout << find(1) << endl; // Output: 3
    cout << find(2) << endl; // Output: 3
    cout << find(3) << endl; // Output: 3
    cout << find(4) << endl; // Output: 4

    return 0;
}
