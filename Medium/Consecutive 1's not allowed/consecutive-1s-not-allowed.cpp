//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	int mod=1e9+7;
// 	ll solve(int ind,int n,vector<vector<ll>> &dp,bool f){
// 	    if(ind == n){
// 	        return (ll)1;
// 	    }
// 	    if(dp[ind][f]!=-1){
// 	        return dp[ind][f] % mod;
// 	    }
// 	    ll pick=0,notpick=0;
// 	    if(f){
// 	        return dp[ind][f]=solve(ind+1,n,dp,0) % mod;
// 	    }
// 	    else{
// 	        return dp[ind][f]=(solve(ind+1,n,dp,1) % mod + solve(ind+1,n,dp,0) % mod) % mod;
// 	    }
// 	   // =(pick % mod + notpick % mod) % mod;
// 	}
	ll countStrings(int n) {
	    // code here
	   vector<ll> dp(n+1,0);
	   // return solve(0,n,dp,0)%mod;
	   dp[1]=2;
	   dp[2]=3;
	   for(int i=3;i<=n;i++){
	       dp[i]=(dp[i-1]%mod + dp[i-2] % mod) % mod;
	   }
	   return dp[n]%mod;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends