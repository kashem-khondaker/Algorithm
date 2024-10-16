#include<bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string st1, st2;

    while (cin >> st1 >> st2) 
    {
        int i = 0, j = 0;
        int cnt = 0;
        while (i < st1.length() && j < st2.length()) 
        {
            if (st1[i] == st2[j]) 
            {
                cnt++;
                j++; 
            }
            i++; 
        }
        
        
        if (cnt == st2.length()) 
        {
            cout << "Possible" << endl;
        } 
        else 
        {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
