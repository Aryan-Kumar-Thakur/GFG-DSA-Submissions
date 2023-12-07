//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int n=S.size();
        int ini=0,len=0;
        for(int i=0;i<n;i++){
            int lo=i-1;
            int hi=i+1;
            while(lo>=0 && S[lo]==S[i]){
                lo--;
            }
            while(hi<n && S[hi]==S[i]){
                hi++;
            }
            while(lo>=0 && hi<n && S[lo]==S[hi]){
                lo--;
                hi++;
            }
            if(hi-lo-1 > len){
                len = hi-lo-1;
                ini=lo+1;
            }
        }
        return S.substr(ini,len);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends