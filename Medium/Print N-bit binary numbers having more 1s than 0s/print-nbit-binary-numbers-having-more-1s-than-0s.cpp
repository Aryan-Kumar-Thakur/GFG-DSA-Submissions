//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    bool check(string &str){
        int oc=0,zc=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='1'){
                oc++;
            }
            else{
                zc++;
            }
            if(zc > oc){
                return false;
            }
        }
        return true;
    }
    void solve(int n,int oc,int zc,string output,vector<string> &ans){
        if(n==0){
            if(oc >= zc && check(output)){
                ans.push_back(output);
            }
            return;
        }
        solve(n-1,oc,zc+1,output+'0',ans);
        solve(n-1,oc+1,zc,output+'1',ans);
    }
public:	
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> ans;
	    string output="";
	    int oc=0,zc=0;
	    solve(n,oc,zc,output,ans);
	    sort(ans.begin(),ans.end(),greater<string>());
	    return ans;
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
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends