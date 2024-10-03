#include <bits/stdc++.h>
using namespace std;

int n, m;
int mart[11][11];

bool valid(int i, int j) 
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int max_sum(int i, int j) 
{
    if (i == n - 1 && j == m - 1) 
    {
        return mart[i][j];
    }

    if (valid(i, j)) 
    {
        int op1 = INT_MIN, op2 = INT_MIN;
        if (i + 1 < n) 
        {
            op1 = mart[i][j] + max_sum(i + 1, j);
        }
        
        if (j + 1 < m) 
        {
            op2 = mart[i][j] + max_sum(i, j + 1);
        }
        return max(op1, op2);
    }
    return INT_MIN;
}

int main() 
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> mart[i][j];
        }
    }

    cout << max_sum(0, 0) << endl;

    return 0;
}
