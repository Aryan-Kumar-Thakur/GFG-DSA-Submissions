//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int ways(int x, int y)
    {
        //code here.
        int mod=1e9+7;
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        dp[0][0]=1;
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(i==0 && j==0) continue;
                int r=0,d=0;
                if(i>0){
                    r=dp[i-1][j];
                }
                if(j>0){
                    d=dp[i][j-1];
                }
                dp[i][j]=(r % mod + d % mod) % mod;
            }
        }
        return dp[x][y] % mod;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends