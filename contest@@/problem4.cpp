// #include<bits/stdc++.h>
// using namespace std;

// int maxBalls(vector<int>& bags) 
// {
//     int n = bags.size();
//     sort(bags.begin(), bags.end(), greater<int>());

//     int count = 0;
//     for (int i = 0; i < n; i++) 
//     {
//         if (bags[i] > i) 
//         {
//             count += bags[i] - i;
//         }
//     }

//     return count;
// }

// int main() 
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin >> n;

//     vector<int> bags(n);
//     for (int i = 0; i < n; i++) 
//     {
//         cin >> bags[i];
//     }

//     int maxBallsCollected = maxBalls(bags);
//     cout << maxBallsCollected << endl;

//     return 0;
// }


///

// //top down approch 
// #include <iostream>
// #include <vector>

// using namespace std;

// int maxBallsDP(vector<int>& bags, int n, vector<int>& dp) {
//     if (n == 0) {
//         return 0;
//     }

//     if (dp[n] != -1) {
//         return dp[n];
//     }

//     int take = bags[n - 1] + maxBallsDP(bags, n - bags[n - 1] - 1, dp);
//     int skip = maxBallsDP(bags, n - 1, dp);

//     dp[n] = max(take, skip);
//     return dp[n];
// }

// int main() {
//     int n;
//     cin >> n;

//     vector<int> bags(n);
//     for (int i = 0; i < n; i++) {
//         cin >> bags[i];
//     }

//     vector<int> dp(n + 1, -1);
//     int maxBallsCollected = maxBallsDP(bags, n, dp);
//     cout << maxBallsCollected << endl;

//     return 0;
// }


// //// bottom up approch .. 
// #include <iostream>
// #include <vector>

// using namespace std;

// int maxBallsDP(vector<int>& bags) {
//     int n = bags.size();
//     vector<int> dp(n + 1, 0);

//     for (int i = 1; i <= n; i++) {
//         dp[i] = max(dp[i - 1], bags[i - 1] + dp[i - bags[i - 1] - 1]);
//     }

//     return dp[n];
// }

// int main() {
//     int n;
//     cin >> n;

//     vector<int> bags(n);
//     for (int i = 0; i < n; i++) {
//         cin >> bags[i];
//     }

//     int maxBallsCollected = maxBallsDP(bags);
//     cout << maxBallsCollected << endl;

//     return 0;
// }