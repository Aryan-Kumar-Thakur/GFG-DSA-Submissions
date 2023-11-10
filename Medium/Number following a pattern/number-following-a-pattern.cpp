//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        int i=1;
        int n=s.size();
        string ans(n+1,'$');
        int j=0,k=0;
        while(j<n && k<n){
            if(s[j]=='I'){
                ans[j]=i+'0';
                i++;
                j++;
                k++;
            }
            else{
                while(s[j]=='D' && j<n){
                    j++;
                }
                int m=j;
                while(j>=k){
                    ans[j]=i+'0';
                    i++;
                    j--;
                }
                j=m+1;
                k=m+1;
            }
        }
        if(s[n-1]=='I'){
            ans[n]=i+'0';
        }
        return ans;
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
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends