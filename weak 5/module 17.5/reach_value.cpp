#include <bits/stdc++.h>
using namespace std;

bool flag;

void reach_value(long long int n, long long int w) 
{
    if (w > n) 
    {
        return;
    }
    if (w == n) 
    {
        flag = true;
        return;
    }
    reach_value(n, w * 10);
    reach_value(n, w * 20);
}

int main() 
{
    long long int t;
    cin >> t;
    while (t--) 
    {
        long long int n;
        cin >> n;
        flag = false;
        reach_value(n, 1);
        if (flag) 
        {
            cout << "YES" << endl;
        } 
        else 
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
