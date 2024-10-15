#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int command;
        cin >> command;

        if (command == 0)
        {
            // Push a value into the priority queue and print the top element
            int x;
            cin >> x;
            pq.push(x);
            cout << pq.top() << endl;
        }
        else if (command == 1)
        {
            // Print the top element (minimum value)
            if (pq.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                cout << pq.top() << endl;
            }
        }
        else if (command == 2)
        {
            // Pop the top element and print the new top or "Empty"
            if (!pq.empty())
            {
                pq.pop();
                if (pq.empty())
                {
                    cout << "Empty" << endl;
                }
                else
                {
                    cout << pq.top() << endl;
                }
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
    }
    
    return 0;
}
