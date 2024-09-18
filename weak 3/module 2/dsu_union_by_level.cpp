#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N];
int level[N];

void initialize(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = -1;
        level[i] = 0;
    }
    
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

// void dsu_union(int node1 , int node2)
// {
//     int leader1 = find(node1);
//     int leader2 = find(node2);
//     par[leader1] = leader2;
// }

void dsu_union_by_size(int node1 , int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (level[leader1] > level[leader2])
    {
        par[leader2] = leader1;
        // level[leader1] += level[leader2];
    }
    else if (level[leader2] > level[leader1])
    {
        par[leader1] = leader2;
    }
    
    else
    {
        par[leader1] = leader2;
        level[leader2] ++;
    }
}

int main() {
    initialize(8);
    dsu_union_by_size(1,2);
    dsu_union_by_size(2,3);
    dsu_union_by_size(4,5);
    dsu_union_by_size(5,6);

    // dsu find
    // cout << find(1) << endl;
    // cout << find(4) << endl;
    dsu_union_by_size(1,4);
    cout << find(3) << endl;
    cout << find(2) << endl;
    return 0;
}
