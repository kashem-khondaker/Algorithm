#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t; 
    while (t--) {
        int n; // Size of the vector
        cin >> n;

        queue<int> q;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            q.push(x);
            pq.push(x);
        }
        int flag = true;
        while (!q.empty())
        {
            if (pq.top()!=q.front())
            {
                flag = false;
            }
            // cout << q.front() << " ";
            pq.pop();
            q.pop();
        }
        
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
