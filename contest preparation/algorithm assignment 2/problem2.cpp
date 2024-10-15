#include <bits/stdc++.h>
using namespace std;

#define ll long long int // Define 'll' as a shorthand for long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n; // Input size of the array
    vector<ll> arr(n);
    vector<ll> prefix_sum(n); // Array to store prefix sums

    // Input elements of the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calculate prefix sums
    prefix_sum[0] = arr[0]; 
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i]; 
    }

    vector<ll> v;
    for (int i = 0; i < n; i++) {
        v.push_back(prefix_sum[i]);
    }
    reverse(v.begin(),v.end());
    for (int val : v)
    {
        cout << val << " ";
    }
    cout << endl; 

    return 0;
}
