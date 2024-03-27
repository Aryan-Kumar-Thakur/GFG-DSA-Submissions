//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    //using bfs algo beacuse no need for checking min path len, at the time we will reach last column will be minimum path length itself
    
    // void makeUnsafeCell(vector<vector<int>> &mat, int m, int n, int delRow[], int delCol[])
    // {
    //     for(int i = 0; i < m; i++)
    //     {
    //         for(int j = 0; j < n; j++)
    //         {
    //             if(mat[i][j] == 0)
    //             {
    //                 for(int k = 0; k < 4; k++)
    //                 {
    //                     int nr = i + delRow[k];
    //                     int nc = j + delCol[k];
    //                     if(nr>=0 && nr<m && nc>=0 && nc<n)
    //                     {
    //                         mat[nr][nc] = 0;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    
     bool check(int i, int j, vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        if(mat[i][j] == 0) return 0;
        if(i+1 < n && mat[i+1][j] == 0) return 0;
        if(i-1 >=0 && mat[i-1][j] == 0) return 0;
        if(j+1 < m && mat[i][j+1] == 0) return 0;
        if(j-1 >=0 && mat[i][j-1] == 0) return 0;
        return 1;
    }
    
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
       int m = mat.size();
       int n = mat[0].size();
       //making all neighbouring cells of land,ines also as 0, means we cannot travel there
       int delRow[] = {-1, 0, +1, 0};
       int delCol[] = {0, +1, 0, -1};
    //   makeUnsafeCell(mat, m, n, delRow, delCol);
       
       //performing bfs algo
       queue<pair<int, pair<int, int>>> q; //{dist, {row, col}}
       vector<vector<int>> vis(m, vector<int>(n, 0));
       for(int i = 0; i < m; i++)
       {
           if(check(i,0,mat)){
               q.push({1, {i, 0}});
           }
       }
       
       while(! q.empty())
       {
           auto it = q.front();
           int dist = it.first;
           int r = it.second.first;
           int c = it.second.second;
           q.pop();
           if(c == n - 1) return dist;
           vis[r][c] = 1;
           for(int k = 0; k < 4; k++)
           {
                int nr = r + delRow[k];
                int nc = c + delCol[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n && check(nr,nc,mat) && vis[nr][nc]==0)
                {
                    q.push({dist + 1, {nr, nc}});
                }
           }
       }
       return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends