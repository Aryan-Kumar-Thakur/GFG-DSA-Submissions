//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string betterString(string str1, string str2) {
        // code here
        int n=str1.size();
        vector<int> dp(n+1,0);
        map<char,int> mp;
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(mp.find(str1[i-1])!=mp.end()){
                dp[i]=(2*dp[i-1] - dp[mp[str1[i-1]]-1]);
            }
            else{
                dp[i]=2*dp[i-1];
            }
            mp[str1[i-1]]=i;
        }
        int m=str2.size();
        vector<int> dp2(m+1,0);
        map<char,int> mp2;
        dp2[0]=1;
        for(int i=1;i<=m;i++){
            if(mp2.find(str2[i-1])!=mp2.end()){
                dp2[i]=(2*dp2[i-1] - dp2[mp2[str2[i-1]]-1]);
            }
            else{
                dp2[i]=2*dp2[i-1];
            }
            mp2[str2[i-1]]=i;
        }
        // cout<<dp[n]<<" "<<dp2[m];
        return (dp[n] >= dp2[m]) ? str1:str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends