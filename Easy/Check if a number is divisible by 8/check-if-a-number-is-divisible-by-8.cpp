//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        int n=s.size();
        int num=0;
        string temp="";
        if(n<=3){
            num=stoi(s);
        }
        else{
            if(s[n-3]=='0' && s[n-2]=='0' && s[n-1]=='0'){
                return 1;
            }
            temp+=s[n-3];
            temp+=s[n-2];
            temp+=s[n-1];
            num=stoi(temp);
        }
        if(num%8==0){
            return 1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends