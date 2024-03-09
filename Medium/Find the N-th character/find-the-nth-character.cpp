//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    char ans='-1';
    void dfs(int ch,int lvl,int idx,int r,int n){
        if(lvl>r || idx>n){
            return;
        }
        if(lvl==r && idx==n){
            // cout<<r<<" "<<idx<<" "<<ch<<endl;
            ans=ch+'0';
            return;
        }
        dfs(ch,lvl+1,2*idx,r,n);
        dfs(1-ch,lvl+1,2*idx+1,r,n);
    }
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        int m=s.size();
        for(int i=0;i<m;i++){
            if(i<=n){
                dfs(s[i]-'0',0,i,r,n);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends