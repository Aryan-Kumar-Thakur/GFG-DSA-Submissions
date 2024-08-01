//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int solve(int ind1,int ind2,int n,int m,string s1,string s2,vector<vector<int>> &dp){
        if(ind1==n){
            return (m-ind2);
        }
        if(ind2==m){
            return (n-ind1);
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        int ans=INT_MAX;
        if(s1[ind1]==s2[ind2]){
            ans=min(ans,solve(ind1+1,ind2+1,n,m,s1,s2,dp));
        }
        else{
            ans=min(ans,1+solve(ind1+1,ind2,n,m,s1,s2,dp));
            ans=min(ans,1+solve(ind1,ind2+1,n,m,s1,s2,dp));
            ans=min(ans,1+solve(ind1+1,ind2+1,n,m,s1,s2,dp));
        }
        return dp[ind1][ind2]=ans;
    }
  public:
    int editDistance(string str1, string str2) {
        // Code here
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,str1,str2,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends