//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    long long solve(vector<vector<int>> &arr,int r,int c,int n,int k,vector<vector<vector<long long>>> &dp){
        if(r==n-1 && c==n-1){
            return (arr[r][c]==k);
        }
        if(r>=n || c>=n || k<0){
            return 0;
        }
        if(dp[r][c][k]!=-1){
            return dp[r][c][k];
        }
        long long left=0,down=0;
        if(r+1 < n){
            left=solve(arr,r+1,c,n,k-arr[r][c],dp);
        }
        if(c+1 < n){
            down=solve(arr,r,c+1,n,k-arr[r][c],dp);
        }
        return dp[r][c][k]=left+down;
    }
public:
    
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
        // Code Here
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(n,vector<long long>(k+1,-1)));
        return solve(arr,0,0,n,k,dp);
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends