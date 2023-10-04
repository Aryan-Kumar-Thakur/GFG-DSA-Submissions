//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
long long int solve(int n,int k,string &s){
    vector<int> mp(26,0);
    	int distinct=0;
    	int j=0;
    	int ans=0;
    	for(int i=0;i<n;i++){
    	    mp[s[i]-'a']++;
    	    if(mp[s[i]-'a']==1){
    	        distinct++;
    	    }
    	    while(distinct > k){
    	       if(mp[s[j]-'a']==1){
    	           distinct--;
    	       }
    	        mp[s[j]-'a']--;
    	        j++;
    	    }
    	       ans+=(i-j+1);
    	}
    	return ans;
}

    long long int substrCount (string s, int k) {
        int n=s.size();
    	long long ans = solve(n,k,s)-solve(n,k-1,s);
    	return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends