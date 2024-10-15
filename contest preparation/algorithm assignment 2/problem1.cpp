#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int n;
    cin >> n;
    set<int> st;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
        q.push(x);
    }
    int st_size = st.size();
    int q_size = q.size();
    // cout << st_size << " " << q_size << endl;
    if (st_size != q_size)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    
    return 0;
}