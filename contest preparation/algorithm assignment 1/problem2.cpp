#include <bits/stdc++.h>
using namespace std;

// Comparator class
class cmp {
public:
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        if (a.first != b.first) {
            return a.first > b.first;  // Ascending order for names
        }
        return a.second < b.second;  // Descending order for values if names are the same
    }
};

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL); 

    int n;
    cin >> n;

    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;

    for (int i = 0; i < n; i++) {
        string name;
        int val;
        cin >> name >> val;
        
        pq.push({name, val}); 
    }

    // Printing elements from priority queue
    while (!pq.empty()) {
        auto p = pq.top();
        cout << p.first << " " << p.second << endl;
        pq.pop();
    }

    return 0;
}
