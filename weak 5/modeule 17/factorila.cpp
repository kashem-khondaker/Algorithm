#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    if (n==0)
    {
        return 1;
    }
    int sub_problem = fact(n-1);
    return sub_problem * n;
}
int main()
{
    int n ;
    cin >> n;
    cout << fact(n) << endl;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans*i;
    }
    cout << ans;
    return 0;
}