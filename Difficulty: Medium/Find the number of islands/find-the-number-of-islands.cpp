//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>> &visited){
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        queue<pair<int,int>> q;
        q.push(make_pair(row,col));
        while(!q.empty()){
            pair<int,int> temp=q.front();
            q.pop();
            int row=temp.first;
            int col=temp.second;
            //traverse in nebours and mark them
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && grid[nrow][ncol]=='1' && visited[nrow][ncol]==0){
                        visited[nrow][ncol]=1;
                        q.push(make_pair(nrow,ncol));
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int> >visited(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col,grid,visited);
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends