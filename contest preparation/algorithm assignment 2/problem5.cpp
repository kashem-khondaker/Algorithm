#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    char ar[n][n];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && i + j == n - 1) {
                // This condition will handle only the middle when n is odd
                ar[i][j] = 'X';
            } else if (i == j) {
                ar[i][j] = '\\'; // Fill the backslash diagonal
            } else if (i + j == n - 1) {
                ar[i][j] = '/';  // Fill the forward slash diagonal
            }
            else
            {
                ar[i][j] = ' ';
            }
        }
    }


    // Print the array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ar[i][j];
        }
        cout << endl; // Move to the next line after printing each row
    }

    return 0;
}
