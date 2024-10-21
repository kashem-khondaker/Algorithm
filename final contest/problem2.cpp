#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void fun(ll n, ll ar[]) 
{
    ll sum = 0;
    
    for (int i = 0; i < n; i++) 
    {
        sum += ar[i];
    }
    
    ll left = 0, right = sum;

    for (int i = 0; i < n; i++) 
    {
        right = right - ar[i];

        if (left == right) 
        {
            cout << ar[i] + left << " " << i + 1 << endl; 
            return;
        }
        
        left += ar[i];
    }
    
    cout << "UNSTABLE" << endl;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n; 
    ll  ar[n];
    
    for (int i = 0; i < n; i++) 
    {
        cin >> ar[i];
    }
    
    fun(n, ar); 
    
    return 0;
}
