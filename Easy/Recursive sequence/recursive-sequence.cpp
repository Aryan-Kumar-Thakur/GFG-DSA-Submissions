//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    long long mod=1e9+7;
    long long x=0;
    long long solve(int n,int cnt){
        if(cnt==n){
            return 1;
        }
        x++;
        return (x % mod *solve(n,cnt+1) % mod) % mod;
    }
    
public:
    long long sequence(int n){
        // code here
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans=(ans % mod + solve(i,0)%mod) % mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends