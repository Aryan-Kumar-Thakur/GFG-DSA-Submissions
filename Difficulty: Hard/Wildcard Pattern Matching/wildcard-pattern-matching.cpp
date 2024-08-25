//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        // code here
        int n=pattern.size();
        int m=str.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[n][m]=1;
        for(int i=n-1;i>=0;i--){
            if(pattern[i]=='*'){
                dp[i][m]=1;
            }
            else{
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans=0;
                if(pattern[i]==str[j] || pattern[i]=='?'){
                    ans=dp[i+1][j+1];
                }
                else if(pattern[i]=='*'){
                    ans=dp[i][j+1] || dp[i+1][j];
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends