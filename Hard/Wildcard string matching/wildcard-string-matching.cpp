//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    bool solve(string &wild, string &pattern,int ind1,int ind2,int n,int m,vector<vector<int>> &dp){
        if(ind2==m){
            while(ind1<n){
                if(wild[ind1]!='*'){
                    return 0;
                }
                ind1++;
            }
            return 1;
        }
        if(ind1==n){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        bool op1=false,op2=false,op3=false;
        if(wild[ind1]==pattern[ind2] || wild[ind1]=='?'){
            op1=solve(wild,pattern,ind1+1,ind2+1,n,m,dp);
        }
        if(wild[ind1]=='*'){
            op2=solve(wild,pattern,ind1+1,ind2,n,m,dp);
            op3=solve(wild,pattern,ind1,ind2+1,n,m,dp);
        }
        return dp[ind1][ind2]=(op1 || op2 || op3);
    }
    public:
    bool match(string wild, string pattern)
    {
        // code here
        int n=wild.size(),m=pattern.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(wild,pattern,0,0,n,m,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends