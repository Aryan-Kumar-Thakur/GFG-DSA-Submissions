//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            if(str1[i]==str2[0]){
                dp[i][0]=1;
                ans=max(ans,dp[i][0]);
            }
        }
        for(int i=0;i<m;i++){
            if(str2[i]==str1[0]){
                dp[0][i]=1;
                ans=max(ans,dp[0][i]);
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int pick=0,notpick=0;
                if(str1[i]==str2[j]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                // notpick=max(dp[i-1][j],dp[i][j-1]);
                // dp[i][j]=max(pick,notpick);
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends