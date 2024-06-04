//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        string ans="";
        int cnt=1;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                cnt++;
            }
            if(cnt==2){
                ans+='0';
                cnt=1;
            }
            else if(cnt==1){
                ans+='1';
                cnt=0;
            }
            else{
                ans+='0';
                cnt=0;
            }
        }
        if(cnt){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        int m=ans.size();
        while(i<m && ans[i]=='0'){
            i++;
        }
        return ans.substr(i);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends