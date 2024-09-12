// class Solution {
// public:

//     bool visited[55][55];
    
//     vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

//     bool valid(int i, int j , int n , int m ,int target,int color, vector<vector<int>> image)
//     {
//         if (i < 0 || i >= n || j < 0 || j >= m || image[i][j] != target || image[i][j]=color)
//             return false;
//         return true;
//     }

//     void dfs(int i, int j , int n , int m ,int target, int color , vector<vector<int>> & image )
//     {
//         image[i][j] = color;
//         visited[i][j] = true;
//         for (int i = 0; i < 4; i++)
//         {
//             int childi = i + d[i].first;
//             int childj = j + d[i].second;
            
//             if (valid(childi, childj , n , m ,target,color, image) == true && visited[childi][childj] == false)
//             {
//                 dfs(childi, childj , n , m ,target, color, image);
//                 // image[childi][childj] = color;
//             }
//         }
//     }

//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
//         int n  = image.size();
//         int m  = image[0].size();
// 				int target = image[sr][sc];
//         memset(visited,false,sizeof(visited) );

//         dfs(sr,sc , n , m,target,color,image);


//         return image;
//     }
// };

// -------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------solve problem ----------------------------------------------------------------


// class Solution 
// {
// public:
//     bool visited[55][55];
//     vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

//     bool valid(int i, int j, int n, int m, int target, int color, vector<vector<int>>& image) 
//     {
//         if (i < 0 || i >= n || j < 0 || j >= m || image[i][j] != target || image[i][j] == color)
//             return false;
//         return true;
//     }

//     void dfs(int i, int j, int n, int m, int target, int color, vector<vector<int>>& image) 
//     {
//         image[i][j] = color;
//         visited[i][j] = true;
//         for (int k = 0; k < 4; k++) {
//             int childi = i + d[k].first;
//             int childj = j + d[k].second;
            
//             if (valid(childi, childj, n, m, target, color, image) && !visited[childi][childj]) 
//             {
//                 dfs(childi, childj, n, m, target, color, image);
//             }
//         }
//     }

//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
//     {
//         int n = image.size();
//         int m = image[0].size();
//         int target = image[sr][sc];
//         memset(visited, false, sizeof(visited));
//         dfs(sr, sc, n, m, target, color, image);
//         return image;
//     }
// };

// --------------------------------------------------------------------------------------------------------------
// Explanation of Fixes

// 1 . Comparison Operator:
// Changed image[i][j]=color to image[i][j] == color in the valid function to correctly compare the values.

// 2 . Loop Variable:
// Changed the inner loop variable in the dfs function from i to k to avoid conflicts with the outer loop variable.

// Great Broo....
