// #include <bits/stdc++.h>
// using namespace std;

// int main() 
// {
//     int n, w;
//     cin >> n >> w;
//     int val[n], wight[n];

//     for (int i = 0; i < n; i++) 
//     {
//         cin >> val[i];
//     }
//     for (int i = 0; i < n; i++) 
//     {
//         cin >> wight[i];
//     }

//     // Create a dp array to store the maximum value for each item and weight limit
//     int dp[n + 1][w + 1];

//     // Initialization part
//     for (int i = 0; i <= n; i++) 
//     {
//         for (int j = 0; j <= w; j++) 
//         {
//             if (i == 0 || j == 0) 
//             {
//                 dp[i][j] = 0; // No items or zero weight limit results in zero value
//             }
//         }
//     }

//     // DP computation part
//     for (int i = 1; i <= n; i++) 
//     {
//         for (int j = 1; j <= w; j++) 
//         {
//             if (wight[i - 1] <= j) 
//             {
//                 // Option 1: Take the item (since it's unbounded, item can be taken multiple times)
//                 int op1 = val[i - 1] + dp[i][j - wight[i - 1]];
//                 // Option 2: Don't take the item
//                 int op2 = dp[i - 1][j];
//                 // Take the maximum of both options
//                 dp[i][j] = max(op1, op2);
//             } 
//             else 
//             {
//                 // If the current item's weight exceeds the current capacity, we can't take it
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     // The maximum value for the given weight limit is stored in dp[n][w]
//     cout << dp[n][w] << endl;

//     return 0;
// }
