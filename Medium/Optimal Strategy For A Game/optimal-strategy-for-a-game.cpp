//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    long long solve(int sind,int eind,int arr[],vector<vector<long long>> &dp){
        if(sind > eind){
            return 0;
        }
        if(dp[sind][eind]!=-1){
            return dp[sind][eind];
        }
        long long fpick=arr[sind]+min(solve(sind+2,eind,arr,dp),solve(sind+1,eind-1,arr,dp));
        long long lpick=arr[eind]+min(solve(sind+1,eind-1,arr,dp),solve(sind,eind-2,arr,dp));
        return dp[sind][eind]=max(fpick,lpick);
    }
    public:
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<long long>> dp(n,vector<long long>(n,-1));
        return solve(0,n-1,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends