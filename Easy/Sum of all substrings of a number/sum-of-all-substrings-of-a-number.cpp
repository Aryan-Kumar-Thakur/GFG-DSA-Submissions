//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        long long MOD=1e9+7;
        long long n = s.length();
        long long sum = 0;
        long long multiplier = 1;  
        for (int i = (int) n - 1; i >= 0; i--) {
            long long digit = s[i] - '0';
            sum = (sum + (digit * multiplier * (i + 1)) % MOD) % MOD;
            multiplier = (multiplier * 10 + 1) % MOD;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends