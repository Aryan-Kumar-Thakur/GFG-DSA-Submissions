//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod=1e9+7;
	public:
		int nthPoint(int n){
		    // Code here
		    if(n==1 || n==2){
		        return n;
		    }
		    int i=1,j=2;
		    for(int k=3;k<=n;k++){
		        int x=j;
		        j=(i+j)%mod;
		        i=x;
		    }
		    return j;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends