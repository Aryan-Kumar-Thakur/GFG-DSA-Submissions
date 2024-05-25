//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int solve(int ind1,int ind2,int n,int m,string &x,string &y,int cx,int cy,vector<vector<int>> &dp){
        if(ind1==n){
            return (m-ind2)*cy;
        }
        if(ind2==m){
            return (n-ind1)*cx;
        }
        if(dp[ind1][ind2]!=1e8){
            return dp[ind1][ind2];
        }
        int op1=1e8,op2=1e8,op3=1e8;
        if(x[ind1]==y[ind2]){
            op1=solve(ind1+1,ind2+1,n,m,x,y,cx,cy,dp);
        }
        else{
            op2=cx+solve(ind1+1,ind2,n,m,x,y,cx,cy,dp);
            op3=cy+solve(ind1,ind2+1,n,m,x,y,cx,cy,dp);
        }
        return dp[ind1][ind2]=min(op1,min(op2,op3));
    }
  public:
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        int n=x.size();
        int m=y.size();
        vector<vector<int>> dp(n,vector<int>(m,1e8));
        return solve(0,0,n,m,x,y,costX,costY,dp);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends