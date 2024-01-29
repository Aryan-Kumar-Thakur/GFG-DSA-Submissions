//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    int solve(int ind1,int ind2,int ind3,int n,int m,int o,string &a,string &b,string &c,vector<vector<vector<int>>> &dp){
        if(ind1>=n || ind2>=m || ind3>=o){
            return 0;
        }
        if(dp[ind1][ind2][ind3]!=-1){
            return dp[ind1][ind2][ind3];
        }
        int pick=0,notpick=0;
        if(a[ind1]==b[ind2] && b[ind2]==c[ind3]){
            pick=1+solve(ind1+1,ind2+1,ind3+1,n,m,o,a,b,c,dp);
        }
        notpick=max(solve(ind1+1,ind2,ind3,n,m,o,a,b,c,dp),max(solve(ind1,ind2+1,ind3,n,m,o,a,b,c,dp)
        ,solve(ind1,ind2,ind3+1,n,m,o,a,b,c,dp)));
        return dp[ind1][ind2][ind3]=max(pick,notpick);
    }
    public:

        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
            int n=A.size();
            int m=B.size();
            int o=C.size();
            vector<vector<vector<int>>> dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
            return solve(0,0,0,n,m,o,A,B,C,dp);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends