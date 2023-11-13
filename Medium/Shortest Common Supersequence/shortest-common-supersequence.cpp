//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    int findlcs(string &str1,string &str2,int m,int n,vector<vector<int>> &dp){
        for(int ind1=1;ind1<=m;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                int pick=0;
                if(str1[ind1-1]==str2[ind2-1]){
                    pick=1+dp[ind1-1][ind2-1];
                }
                int notpick=max(dp[ind1][ind2-1],dp[ind1-1][ind2]);
                dp[ind1][ind2]=max(pick,notpick);
            }
        }
        return dp[m][n];
    }
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        int ans=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        ans=findlcs(X,Y,m,n,dp);
        return (m+n-ans);
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends