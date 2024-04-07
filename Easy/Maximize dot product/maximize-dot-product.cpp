//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int solve(int ind1,int ind2,int a[],int b[],int n,int m,vector<vector<int>> &dp){
        if(ind2==m){
            return 0;
        }
        if(ind1==n && ind2<m){
            return -1e8;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        int pick=0,notpick=0;
        pick=a[ind1]*b[ind2] + solve(ind1+1,ind2+1,a,b,n,m,dp);
        notpick=0+solve(ind1+1,ind2,a,b,n,m,dp);
        return dp[ind1][ind2]=max(pick,notpick);
    }
		
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
		return solve(0,0,a,b,n,m,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends