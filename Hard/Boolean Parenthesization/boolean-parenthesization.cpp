//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int mod=1003;
    int solve(int n,string &s,int i,int j,vector<vector<vector<int>>> &dp,bool f){
        if(i>j){
            return 0;
        }
        if(i==j){
            if(f){
                return (s[i]=='T');
            }
            else{
                return (s[i]=='F');
            }
        }
        if(dp[i][j][f]!=-1){
            return dp[i][j][f];
        }
        int ways=0;
        for(int k=i+1;k<j;k++){
            if(s[k]=='|' || s[k]=='&' || s[k]=='^'){
                int lefttrue=solve(n,s,i,k-1,dp,1);
                int leftfalse=solve(n,s,i,k-1,dp,0);
                int righttrue=solve(n,s,k+1,j,dp,1);
                int rightfalse=solve(n,s,k+1,j,dp,0);
                if(s[k]=='|'){
                    if(f){
                        ways=(ways % mod + (lefttrue % mod * rightfalse % mod) %mod+ 
                        (leftfalse % mod * righttrue % mod) %mod + 
                        (lefttrue % mod * righttrue % mod) %mod ) % mod;
                    }
                    else{
                        ways= (ways%mod + (leftfalse%mod * rightfalse%mod)%mod) % mod;
                    }
                }
                else if(s[k]=='&'){
                    if(f){
                        ways=(ways % mod +  + 
                        (lefttrue % mod * righttrue % mod)%mod) % mod;
                    }
                    else{
                        ways= (ways%mod + (lefttrue % mod * rightfalse % mod) %mod+ 
                        (leftfalse % mod * righttrue % mod) %mod +
                        (leftfalse%mod * rightfalse%mod)%mod) % mod;
                    }
                }
                else if(s[k]=='^'){
                    if(f){
                        ways=(ways % mod + (lefttrue % mod * rightfalse % mod) %mod+ 
                        (leftfalse % mod * righttrue % mod) %mod) % mod;
                    }
                    else{
                        ways= (ways%mod + (leftfalse%mod * rightfalse%mod)%mod + (lefttrue % mod * righttrue % mod)%mod) % mod;
                    }
                }
            }
        }
        return dp[i][j][f]=(ways)%mod;
    }
public:
    int countWays(int N, string S){
        // code here
        int i=0,j=N-1;
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(3,-1)));
        bool f=1;
        return solve(N,S,i,j,dp,f);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends