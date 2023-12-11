//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int dr[3]={-1,0,1};
    int dc[3]={1,1,1};
    
    int solve(int r,int c,int n,int m,vector<vector<int>> &dp,vector<vector<int>> &M){
        if(r < 0 || r>=n || c>=m){
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int ans=INT_MIN;
        for(int i=0;i<3;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            ans=max(ans,M[r][c]+solve(nr,nc,n,m,dp,M));
        }
        return dp[r][c] = ans;
    }
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int ans=INT_MIN;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            ans=max(ans,solve(i,0,n,m,dp,M));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends