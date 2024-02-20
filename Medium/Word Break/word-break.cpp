//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
    int solve(string &a,int ind,set<string> &st,vector<int> &dp,int n){
        if(ind==n){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int ans=0;
        for(int j=ind;j<n;j++){
            string k=a.substr(ind,j-ind+1);
            if(st.find(k)!=st.end()){
                ans=ans || solve(a,j+1,st,dp,n);
            }
        }
        return dp[ind]=ans;
    }
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        int n=A.size();
        set<string> st;
        for(auto it:B){
            st.insert(it);
        }
        vector<int> dp(n,-1);
        // dp[0]=1;
        // for(int i=1;i<=n;i++){
        //     int ans=0;
        //     for(int j=i;j<=n;j++){
        //         string k=A.substr(i-1,j-i+1);
        //         if(st.find(k)!=st.end()){
        //             ans=
        //         }
        //     }
        // }
        return solve(A,0,st,dp,n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends