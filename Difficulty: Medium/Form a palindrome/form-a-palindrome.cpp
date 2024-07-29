//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    int lcs(string str1,string str2,int n,vector<vector<int>> &dp){
         for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
        
    }
  public:
    int countMin(string str){
    //complete the function here
    string k=str;
    reverse(k.begin(),k.end());
    int n=str.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    return n-lcs(str,k,n,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends