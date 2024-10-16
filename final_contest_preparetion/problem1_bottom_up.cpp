#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        int weight[n];
        int value[n];

        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> value[i];
        }

        int dp[n+1][w+1];
        // Initialize DP table
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= w ; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
            }
        }

        // Fill DP table
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (weight[i-1] <= j)  // Corrected condition
                {
                    int option1 = value[i-1] + dp[i-1][j - weight[i-1]];
                    int option2 = dp[i-1][j];
                    dp[i][j] = max(option1, option2);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        cout << dp[n][w] << endl;
    }
    
    return 0;
}
