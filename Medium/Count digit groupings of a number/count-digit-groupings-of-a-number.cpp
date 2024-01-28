//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    int solve(int ind,int n,string &str,vector<vector<int>> &dp,int prev){
        if(ind>=n){
            return 1;
        }
        if(dp[ind][prev]!=-1){
            return dp[ind][prev];
        }
        int ans=0;
        int currsum=0;
        for(int i=ind;i<n;i++){
            currsum+=str[i]-'0';
            // cout<<x<<endl;
            if(currsum>=prev){
                // cout<<x<<endl;
                ans+=solve(i+1,n,str,dp,currsum);
            }
        }
        return dp[ind][prev] = ans;
    }
	public:
	int TotalCount(string str){
	    // Code here
	    int n=str.size();
	    int m=0;
    for(int i=0;i<n;i++){
        m+=str[i]-'0';
    }
	    vector<vector<int>> dp(n,vector<int>(m+1,-1));
	    return solve(0,n,str,dp,0);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends