//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int solve(int arr[],int prev,int ind,int n,vector<vector<int>> &dp){
        if(ind==n){
            return 0;
        }
        if(dp[prev+1][ind]!=-1){
            return dp[prev+1][ind];
        }
        int pick=0,notpick=0;
        if(prev==-1 || arr[ind] > arr[prev]){
            pick=arr[ind]+solve(arr,ind,ind+1,n,dp);
        }
        notpick=solve(arr,prev,ind+1,n,dp);
        return dp[prev+1][ind]=max(pick,notpick);
    }
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n+1,vector<int>(n,-1));
	    return solve(arr,-1,0,n,dp);
	   // for(int i=0;i<n;i++){
	   //     dp[i][0]=arr[i];
	   // }
	   // for(int i=0;i<n;i++){
	   //     for(int j=1;j<=i;j++){
	   //         if(arr[j-1]<arr[i-1]){
	   //             dp[i][j]=max(dp[i][j],arr[i]+dp[i-1][j-1]);
	   //         }
	   //     }
	   // }
	   // return dp[n+1][n];
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends