// class Solution {
// public:
//     int knapsack(int n, vector<int>& cost, vector<int>& dp) 
//     {
//         if (n == 0) 
//         {
//             return cost[0];
//         }
//         if (n == 1) 
//         {
//             return cost[1];
//         }
//         if (dp[n] != -1) 
//         {
//             return dp[n];
//         }
//         int op1 = cost[n] + knapsack(n - 1, cost, dp);
//         int op2 = cost[n] + knapsack(n - 2, cost, dp);
//         dp[n] = min(op1, op2);
//         return dp[n];
//     }

//     int minCostClimbingStairs(vector<int>& cost) 
//     {
//         int n = cost.size();
//         vector<int> dp(n, -1);
//         int kp1 = knapsack(n-1, cost, dp);
//         int kp2 = knapsack(n-2, cost, dp);
//         return min(kp1 , kp2);
//     }
// };
