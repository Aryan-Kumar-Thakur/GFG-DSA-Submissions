//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    // int solve(int arr[],int prev,int ind,int n,vector<vector<int>> &dp){
    //     if(ind >= n){
    //         return 0;
    //     }
    //     if(dp[prev+1][ind]!=-1){
    //         return dp[prev+1][ind];
    //     }
    //     int pick=0,notpick=0;
    //     if(prev==-1 || arr[ind] > arr[prev]){
    //         pick=arr[ind]+solve(arr,ind,ind+1,n,dp);
    //     }
    //     notpick=0+solve(arr,prev,ind+1,n,dp);
    //     return dp[prev+1][ind]=max(pick,notpick);
    // }
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> dp(n,0);
	    for(int i=0;i<n;i++){
	        dp[i]=arr[i];
	    }
	    for(int ind=1;ind<n;ind++){
	        for(int prev=ind-1;prev>=0;prev--){
	            if(arr[prev] < arr[ind]){
	                dp[ind]=max(dp[ind],arr[ind]+dp[prev]);
	            }
	        }
	    }
	    int ans=0;
	    for(int i=0;i<n;i++){
	        ans=max(ans,dp[i]);
	    }
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