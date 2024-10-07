#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; 
    while (t--)
    {
        int n, M;
        cin >> n >> M; 
        int target = 1000 - M; 
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i]; 
        }

        if (target < 0) {
            cout << "NO" << endl; 
            continue;
        }

        bool dp[n + 1][target + 1]; 
        
        dp[0][0] = true;
        for (int i = 1; i <= target; i++)
            dp[0][i] = false;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[n][target])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
