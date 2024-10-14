#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            st.insert(x);
        }

        // No need to sort since set stores elements in sorted order
        for (auto it = st.begin(); it != st.end(); it++)
        {
            cout << *it << " ";  
        }
        cout << endl;
    }

    return 0;
}
