//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int coutSetBits(int x){
        int cnt=0;
        for(int i=0;i<32;i++){
            if(x & (1<<i)){
                cnt++;
            }
        }
        return cnt;
    }
public:
	int is_bleak(int n)
	{
	    // Code here.
	    int k=coutSetBits(n);
	    if(k==1){
	        return 0;
	    }
	    for(int i=1;i<min(31,n);i++){
	       // cout<<(n-i)<<endl;
	        int l=coutSetBits(n-i);
	       // cout<<l<<endl;
	        if(i==l){
	            return 0;
	        }
	    }
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends