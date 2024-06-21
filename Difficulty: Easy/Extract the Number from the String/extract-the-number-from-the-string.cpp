//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) {

        // code here
          int n = s.length();
        string ans="";
        bool f=1;
        long long maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(s[i]>='0' and s[i]<='9'){
                if(s[i]=='9'){
                   f=0;
                }
                else{
                ans+=s[i];
                }
            }
            if(s[i]==' ' and ans!="" and f==1){
                long long num = stol(ans);
                maxi=max(maxi,num);
                ans="";
                f=1;
            }
            if(s[i]==' ') {
                ans="";
                f=1;
                
            }
        }
        if(maxi==INT_MIN) return -1;
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends