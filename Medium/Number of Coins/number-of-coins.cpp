//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int n=M;
	    vector<vector<int>> dp(M,vector<int>(V+1,1e7));
	    for(int i=0;i<n;i++){
	        dp[i][0]=0;
	    }
	    for(int i=1;i<=V;i++){
	        if(i % coins[0] == 0){
	            dp[0][i]=(i/coins[0]);
	        }
	    }
	    for(int i=1;i<n;i++){
	        for(int j=1;j<=V;j++){
	            int pick=1e7,notpick=1e7;
	            if(j>=coins[i]){
	                pick=1+min(dp[i][j-coins[i]],dp[i-1][j-coins[i]]);
	            }
	            notpick=0+dp[i-1][j];
	            dp[i][j]=min(pick,notpick);
	        }
	    }
	    return (dp[n-1][V]>=1e7)? -1 : dp[n-1][V];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends