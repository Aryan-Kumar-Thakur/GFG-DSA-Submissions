//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    bool ispalli(int i,int j,string &str){
        while(i<j){
            if(str[i]!=str[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
public:
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int ways=0;
            int mini=INT_MAX;
            for(int k=i;k<n;k++){
                if(ispalli(i,k,str)){
                    ways=1+dp[k+1];
                    mini=min(mini,ways);
                }
            }
            dp[i]=mini;
        }
        return dp[0]-1;
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