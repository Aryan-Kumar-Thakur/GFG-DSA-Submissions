//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    // Your code goes here
	    vector<int> dp(V+1,INT_MAX);
	    dp[0]=0;
	    for(int i=1;i<=V;i++){
	        for(int j=0;j<M;j++){
	            if(i>=coins[j]){
	                int x=dp[i-coins[j]];
	                if(x!=INT_MAX){
	                    dp[i]=min(dp[i],x+1);
	                }
	            }
	        }
	    }
	    return dp[V]==INT_MAX? -1:dp[V];
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

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends