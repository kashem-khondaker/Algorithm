#include<bits/stdc++.h>
using namespace std;

int totalChocolates(int r) 
{
    if (r < 3) 
    {
        return 0;
    }
    int x = r / 3;
    int y = r % 3;
    return x + totalChocolates(x + y);
}

int main() 
{
    int T;
    cin >> T;
    while (T--) 
    {
        int N;
        cin >> N;
        int p = N / 5;
        int total = p + totalChocolates(p);
        cout << total << endl;
    }
    return 0;
}
