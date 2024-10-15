#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, X; // Sizes of the arrays and index X
    cin >> n1 ;

    vector<int> A(n1);

    // Input elements for array A
    for (int i = 0; i < n1; i++) {
        cin >> A[i];
    }
    cin >> n2; 
    vector<int> B(n2);

    // Input elements for array B
    for (int i = 0; i < n2; i++) {
        cin >> B[i];
    }
    cin >> X;

    // Insert array B at index X in array A
    A.insert(A.begin() + X, B.begin(), B.end());

    // Print the elements of modified array A
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
