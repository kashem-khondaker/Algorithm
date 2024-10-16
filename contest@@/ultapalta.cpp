#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<char> v;
    for(char c : s)
    {
        
        if(c >= 'A' && c <= 'Z')
        {
            c = c + 32;
        }
        v.push_back(c);
    }

    for (int i = v.size()-1; i >= 0; i--)
    {
        cout << v[i];
    }
    
    return 0;
}
