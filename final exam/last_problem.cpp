#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n ;
        cin >> n;
        int ar[n];
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
            v.push_back(ar[i]);
        }
        sort(v.begin(),v.end(),greater<int>());
    
        int val1 = v[0];
        int val2 = v[1];

        pair<int,int> p1;
        pair<int,int> p2;
        
        for (int i = 0; i < n; i++)
        {
            if (ar[i] == val1)
            {
                p1 = {val1,i};
            }
            if (ar[i] == val2)
            {
                p2 = {val2,i};
            }
            
        }
        
        // cout << p1.first << " " << p1.second << endl << p2.first << " " << p2.second << endl;
        if (p1.second < p2.second)
        {
            cout << p1.second << " " << p2.second << endl;
        }
        else
        {
            cout << p2.second << " " << p1.second << endl;
        }
        
    }
    
    return 0;
}