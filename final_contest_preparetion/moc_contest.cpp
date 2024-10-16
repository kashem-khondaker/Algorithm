#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector <int> v(N);
int n;
int sum;
int halfsum;
int half;
int dp[20] [15005] [10];

int diff(int i, int s, int coins){
    if(i == n){
        if(coins == half){
            return abs(sum - 2*s);
        }
        return INT_MAX;
    }

    if(dp[i][s][coins] != -1){
        return dp[i][s][coins];
    }


    int op1 = diff(i+1, s+v[i], coins+1);
    int op2 = diff(i+1, s, coins);

    return dp[i][s][coins] = min(op1,op2);

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        v.clear();
        v.resize(n);
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
            sum+=v[i];

        }
        half = (n/2);
        if(n%2){
            half++;
        }
        memset(dp, -1, sizeof(dp));

        if(n==1){
            cout<<v[0]<<endl;
            continue;
        }
        else{
            int i = 0 , s = 0, coins = 0;
            int x= diff(i, s, coins);
            cout<<x<<endl;
        }
     
 
    }
    
    
    return 0;
}

