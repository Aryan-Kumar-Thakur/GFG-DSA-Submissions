//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int kPalindrome(string s1, int n, int k)
    {
        // code here
        string s2=s1;
        reverse(s2.begin(),s2.end());
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(s1[i]==s2[0]){
                dp[i][0]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(s1[0]==s2[i]){
                dp[0][i]=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(s1[i]==s2[j]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int cnt=n-dp[n-1][n-1];
        if(cnt<=k){
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends