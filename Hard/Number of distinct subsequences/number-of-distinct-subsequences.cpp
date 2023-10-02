//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    int mod=1e9+7;
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n=s.size();
	    map<char,int> mp;
	    vector<long long> dp(n+1,0);
	    dp[0]=1;
	    for(int i=1;i<=n;i++){
	        if(mp.find(s[i-1])==mp.end()){
	            dp[i]=(2*dp[i-1])%mod;
	        }
	        else{
	            dp[i]=(2*dp[i-1]%mod - dp[mp[s[i-1]]-1]%mod + mod)%mod;
	        }
	        mp[s[i-1]]=i;
	    }
	    return (int)(dp[n]%mod);
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends