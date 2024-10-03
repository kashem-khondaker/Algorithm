#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, vector<pair<int, int>>& buge, int W) 
{
    if (n == 0 || W == 0)
        return 0;
    if (buge[n - 1].first <= W) 
    {
        // Two options: take it or leave it
        int op1 = knapsack(n - 1, buge, W - buge[n - 1].first) + buge[n - 1].second;
        int op2 = knapsack(n - 1, buge, W);
        return max(op1, op2);
    } 
    else 
    {
        // One option: leave it
        return knapsack(n - 1, buge, W);
    }
}

int main() 
{
    int n, W;
    cin >> n >> W;
    vector<pair<int, int>> buge;

    for (int i = 0; i < n; ++i) 
    {
        int weight, value;
        cin >> weight >> value;
        buge.push_back({weight, value});
    }

    cout << knapsack(n, buge, W) << endl;
    return 0;
}
