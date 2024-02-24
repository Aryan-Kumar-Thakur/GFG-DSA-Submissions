//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int solve(int n,vector<int> &dp){
        if(n<=11){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;
        ans=solve(n/2,dp)+solve(n/3,dp)+solve(n/4,dp);
        return dp[n]=ans;
    }
    public:
        int maxSum(int n)
        {
            //code here.
            vector<int> dp(n+1,-1);
            return solve(n,dp);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends