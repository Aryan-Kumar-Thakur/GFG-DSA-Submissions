//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    vector<string> ans;
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,1,-1};
    string k="UDRL";
    bool check(int r,int c,int n,vector<vector<int>> &mat,vector<vector<int>> &vis){
        return r>=0 && r<n && c>=0 && c<n && mat[r][c] && !vis[r][c];
    }
    void solve(int r,int c,int n,string output,vector<vector<int>> &mat,vector<vector<int>> &vis){
        if(r==n-1 && c==n-1){
            ans.push_back(output);
            return;
        }
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(check(nr,nc,n,mat,vis)){
                solve(nr,nc,n,output+k[i],mat,vis);
            }
        }
        vis[r][c]=0;
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n=mat.size();
        string output="";
        if(mat[0][0]==0 || mat[n-1][n-1]==0){
            return {"-1"};
        }
        vector<vector<int>> vis(n,vector<int>(n,0));
        solve(0,0,n,output,mat,vis);
        if(ans.size()==0){
            return {"-1"};
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends