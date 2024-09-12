#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> mat[n];
    
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (mat[x].empty())
        {
            cout << -1 << endl;
        }
        else
        {
            vector<int> v;
            for (int i = 0; i < mat[x].size(); i++)
            {
                v.push_back(mat[x][i]);
            }
            sort(v.begin(), v.end(), greater<int>());

            for (int i : v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
