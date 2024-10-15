#include<bits/stdc++.h>
using namespace std;

class student {
public:
    string name;
    int roll;
    int marks;

    student(string name, int roll, int marks) {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

// Comparator class
class cmp {
public:
    bool operator()(student a, student b) {
        if (a.marks == b.marks) {
            // If marks are the same, compare roll numbers (smaller roll comes first)
            return a.roll > b.roll;
        }
        // Otherwise, higher marks come first
        return a.marks < b.marks;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    priority_queue<student, vector<student>, cmp> pq;

    // Input the initial set of students
    for (int i = 0; i < n; i++) {
        string name;
        int roll;
        int marks;
        cin >> name >> roll >> marks;
        pq.push(student(name, roll, marks));
    }

    int q;
    cin >> q;

    // Process the commands
    while (q--) {
        int command;
        cin >> command;

        if (command == 0) {
            // Add a new student and print the top student
            string name;
            int roll;
            int marks;
            cin >> name >> roll >> marks;
            pq.push(student(name, roll, marks));
            student st = pq.top();
            cout << st.name << " " << st.roll << " " << st.marks << endl;

        } else if (command == 1) {
            // Print the top student
            if (pq.empty()) {
                cout << "Empty" << endl;
            } else {
                student st = pq.top();
                cout << st.name << " " << st.roll << " " << st.marks << endl;
            }

        } else if (command == 2) {
            // Remove the top student and print the new top student
            if (pq.empty()) {
                cout << "Empty" << endl;
            } else {
                pq.pop();
                if (pq.empty()) {
                    cout << "Empty" << endl;
                } else {
                    student st = pq.top();
                    cout << st.name << " " << st.roll << " " << st.marks << endl;
                }
            }
        }
    }

    return 0;
}
