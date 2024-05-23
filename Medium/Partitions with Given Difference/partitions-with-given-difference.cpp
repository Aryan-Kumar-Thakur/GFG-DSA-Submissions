//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int mod=1e9+7;
    int solve(int n,int d,int sum,int s1,vector<int> &arr,vector<vector<int>> &dp,int ind){
        if(ind==n){
            int s2=sum-s1;
            return ((s1-s2) == d);
        }
        if(dp[ind][s1]!=-1){
            return dp[ind][s1];
        }
        int pick = solve(n,d,sum,s1+arr[ind],arr,dp,ind+1);
        int notpick = solve(n,d,sum,s1,arr,dp,ind+1);
        return dp[ind][s1]=(pick+notpick)%mod;
    }
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return  solve(n,d,sum,0,arr,dp,0)%mod;
        // sum+=d;
        // if(sum & 1 || sum-d < 0){
        //     return 0;
        // }
        // sum/=2;
        //  vector<vector<int>> dp(n,vector<int>(sum+1,0));
        //   for(int i=0;i<n;i++){
        //     dp[i][0]=1;
        // }
        // if(arr[0]==0){
        //     dp[0][arr[0]]=2;
        // }
        // else if(arr[0]<=sum){
        //     dp[0][arr[0]]=1;
        // }
        // for(int ind=1;ind<n;ind++){
        //     for(int s=0;s<=sum;s++){
        //         int pick=0;
        //         if(s-arr[ind]>=0){
        //             pick=dp[ind-1][s-arr[ind]];
        //         }
        //         int notpick=dp[ind-1][s];
        //         dp[ind][s]=(pick+notpick)%mod;
        //     }
        // }
        // return (dp[n-1][sum])%mod;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends