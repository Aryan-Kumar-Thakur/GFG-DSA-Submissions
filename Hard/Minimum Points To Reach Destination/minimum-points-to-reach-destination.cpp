//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int solve(int r,int c,int m,int n,vector<vector<int>> &points,vector<vector<int>> &dp){
        if(r==m-1 && c==n-1){
            return 1-points[r][c];
        }
        if(r >= m || c >= n){
            return 1e9;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int dn = solve(r+1,c,m,n,points,dp);
        int rg = solve(r,c+1,m,n,points,dp);
        return dp[r][c]=max(1,min(dn,rg)-points[r][c]);
    }

	public:
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(m,vector<int>(n,-1));
	    int ans=solve(0,0,m,n,points,dp);
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends