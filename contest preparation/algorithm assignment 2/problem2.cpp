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
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calculate prefix sums
    prefix_sum[0] = arr[0]; 
    for (ll i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i]; 
    }

    // Print the prefix sums in reverse order
    for (ll i = n - 1; i >= 0; i--) {
        cout << prefix_sum[i] << " ";
    }
    cout << endl; 

    return 0;
}
