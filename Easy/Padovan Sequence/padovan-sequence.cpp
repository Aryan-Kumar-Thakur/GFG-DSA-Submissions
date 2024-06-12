//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
       //code here
       int mod=1e9+7;
       if(n<=2){
           return 1;
       }
       int p1=1,p2=1,p3=1;
       for(int i=3;i<=n;i++){
           int p4=(p1 % mod + p2 % mod) % mod;
           p1=p2;
           p2=p3;
           p3=p4;
       }
       return (p3 % mod);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends