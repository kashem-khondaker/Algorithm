#include <bits/stdc++.h>
using namespace std;

class student 
{
public:
    string name;
    int val;

    student(string name, int val) 
    {
        this->name = name;
        this->val = val;
    }
};

// Comparator class
class cmp {
public:
    bool operator()(student a, student b) 
    {
        if (a.name != b.name) {
            return a.name > b.name;  // Ascending order for names
        }
        return a.val < b.val;  // Descending order for values if names are the same
    }
};

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<student, vector<student>, cmp> pq;

    for (int i = 0; i < n; i++) 
    {
        string name;
        int val;
        cin >> name >> val;

        student Student(name, val);
        pq.push(Student);
    }

    // Printing elements from priority queue
    while (!pq.empty()) 
    {
        student p = pq.top();
        cout << p.name << " " << p.val << endl;
        pq.pop();
    }

    return 0;
}
