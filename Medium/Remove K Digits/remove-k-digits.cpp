//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        stack<char> st;
        int n=S.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && K>0 && st.top() > S[i]){
                K--;
                st.pop();
            }
            st.push(S[i]);
        }
        if(st.empty()){
            return "0";
        }
        while(K--){
            st.pop();
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        if(i==ans.size()){
            return "0";
        }
        ans=ans.substr(i,ans.size()-i+1);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends