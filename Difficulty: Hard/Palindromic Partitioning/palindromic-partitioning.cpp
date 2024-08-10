//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    bool ispalli(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(int ind,string &str,int n,vector<int> &dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int ans=INT_MAX;
        for(int i=ind;i<n;i++){
            if(ispalli(str,ind,i)){
                ans=min(ans,1+solve(i+1,str,n,dp));
            }
        }
        return dp[ind]=ans;
    }
public:
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<int> dp(n,-1);
        return solve(0,str,n,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends