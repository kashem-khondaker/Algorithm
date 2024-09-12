#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];

void printval(int X) 
{ 
    vector<int> val = v[X];
    sort(val.begin(), val.end(), greater<int>());
    
    for (int node : val) 
    {
        cout << node << " ";
    }
    cout << endl;
}

int main() 
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i) 
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    int q;
    cin >> q;
    while (q--)
    {
        int X;
        cin >> X;
        printval(X);
    }
    
    return 0;
}
