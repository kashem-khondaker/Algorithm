// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e3+5;
// vector<int> v[N];
// bool visited[N];
// int level[N];

// void bfs(int src) 
// {
//     queue<int> q;
//     q.push(src);
    
//     visited[src] = true;
//     level[src] = 0;

//     while (!q.empty()) 
//     {
//         int parent = q.front();
//         q.pop();

//         for (int child : v[parent]) 
//         {
//             if (!visited[child]) 
//             {
//                 q.push(child);
//                 visited[child] = true;
//                 level[child] = level[parent] + 1;
//             }
//         }
//     }
// }


// int main() 
// {
//     int n, e;
//     cin >> n >> e;

//     while (e--) 
//     {
//         int a, b;
//         cin >> a >> b;
        
//         v[a].push_back(b); 
//     }

//     int q;
//     cin >> q;
    
//     while (q--) 
//     {
//         int src, dest;
//         cin >> src >> dest;

//         memset(visited, false, sizeof(visited));
//         memset(level, -1, sizeof(level));

//         bfs(src);

//         if (src == dest)
//         {
//             cout << "YES" << endl;
//         }
//         else if (level[dest] == 1 ) 
//         {
//             cout << "YES" << endl;
//         } 
//         else 
//         {
//             cout << "NO" << endl;
//         }
        
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e3+5;  
// vector<int> v[N];
// bool visited[N];
// int level[N];

// void bfs(int src) 
// {
//     queue<int> q;
//     q.push(src);
    
//     visited[src] = true;
//     level[src] = 0;

//     while (!q.empty()) 
//     {
//         int parent = q.front();
//         q.pop();

//         for (int child : v[parent]) 
//         {
//             if (!visited[child]) 
//             {
//                 q.push(child);
//                 visited[child] = true;
//                 level[child] = level[parent] + 1;
//             }
//         }
//     }
// }

// int main() 
// {
//     int n, e;
//     cin >> n >> e;

    
//     for (int i = 0; i < n; i++) {
//         v[i].clear();  
//     }

    
//     while (e--) 
//     {
//         int a, b;
//         cin >> a >> b;
//         v[a].push_back(b); 
//     }

//     int q;
//     cin >> q;
    
//     while (q--) 
//     {
//         int src, dest;
//         cin >> src >> dest;

//         memset(visited, false, sizeof(visited));
//         memset(level, -1, sizeof(level));
        

//         bfs(src);

//         if (visited[dest])  
//         {
            
//             if (level[dest] == 1) 
//             {
//                 cout << "YES" << endl;
//             } 
//             else 
//             {
//                 cout << "NO" << endl;
//             }
//         }
//         else 
//         {
//             cout << "NO" << endl;  
//         }
//     }
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e3;

// vector<int> v[N];

// bool bfs(int src, int dest) 
// {
//     for (int child : v[src]) 
//     {
//         if (child == dest) 
//         {
//             return true;
//         }
//     }
//     return false;
// }

// int main() 
// {
//     int n, e;
//     cin >> n >> e;

//     while (e--) 
//     {
//         int a, b;
//         cin >> a >> b;
//         v[a].push_back(b); 
//     }

//     int q;
//     cin >> q;
//     while (q--) {
//         int src, dest;
//         cin >> src >> dest;

//         if (bfs(src, dest)) 
//         {
//             cout << "YES" << endl;
//         } 
//         else 
//         {
//             cout << "NO" << endl;
//         }
//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, e;  
    cin >> n >> e;
    int adjMatrix[n][n];

    
    memset(adjMatrix, 0, sizeof(adjMatrix));

    
    for (int i = 0; i < n; i++) 
    {
        adjMatrix[i][i] = 1;
    }

    
    for (int i = 0; i < e; i++) 
    {
        int a, b;
        cin >> a >> b;
        adjMatrix[a][b] = 1;  
    }

    int q; 
    cin >> q;

    while (q--) 
    {
        int src, dest;
        cin >> src >> dest;

        if (adjMatrix[src][dest] == 1) 
        {
            cout << "YES" << endl;  
        } 
        else 
        {
            cout << "NO" << endl;   
        }
    }

    return 0;
}
