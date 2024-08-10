//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int solve(int k,int n,vector<vector<int>> &dp){
        if(n==0 || n==1){
            return n;
        }
        if(k==1){
            return n;
        }
        if(dp[k][n]!=-1){
            return dp[k][n];
        }
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            int ways=1+max(solve(k-1,i-1,dp),solve(k,n-i,dp));
            ans=min(ans,ways);
        }
        return dp[k][n]=ans;
    }
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends