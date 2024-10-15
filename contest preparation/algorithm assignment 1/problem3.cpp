#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string s;
        getline(cin,s);
        cin.ignore();
        stringstream ss (s);
        string word;
        int n = 0;
        string max;
        map<string,int> mp;
        while (ss >> word)
        {
            mp[word] = mp[word] + 1;
            if (mp[word] > n)
            {
                n = mp[word];
                max = word;
            }
            // cout << word << endl;
            // cout << word << " " << mp[word] << " " << n << endl;
            
        }
        cout << max << " " << n << endl;
    }
    
    return 0;
}