//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    bool solve(int n,int coins[],int sum,vector<vector<int>> &dp,int ind){
        if(ind==n){
            if(sum && ((sum%20==0 )|| (sum%24==0) || (sum==2024))){
                return 1;
            }
            return 0;
        }
        //  if(sum && (sum%20==0 || sum%24==0 || sum==2024)){
        //         return 1;
        //     }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        bool op1=false,op2=false;
        op1 =solve(n,coins,sum+coins[ind],dp,ind+1);
        op2=solve(n,coins,sum,dp,ind+1);
        return dp[ind][sum]=(op1 || op2);
    }
    public:
    int isPossible(int N , int coins[]) 
    {
        vector<vector<int>> dp(N,vector<int>(2025,-1));
        return solve(N,coins,0,dp,0);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends