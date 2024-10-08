//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(W+1,0));
        for(int i=1;i<=W;i++){
            if(i>=wt[0]){
                dp[0][i]=(i/wt[0])*val[0];
            }
        }
        for(int i=1;i<N;i++){
            int pick=0,notpick=0;
            for(int j=1;j<=W;j++){
                if(j>=wt[i]){
                    pick=val[i]+dp[i][j-wt[i]];
                }
                notpick=0+dp[i-1][j];
                dp[i][j]=max(pick,notpick);
            }
        }
        return dp[N-1][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends