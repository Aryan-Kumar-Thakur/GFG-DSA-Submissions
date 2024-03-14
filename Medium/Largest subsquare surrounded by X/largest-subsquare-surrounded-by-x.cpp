//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    void solverow(vector<vector<char>> &a,vector<vector<int>> &rows,int n){
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(a[i][j]=='X'){
                    cnt++;
                }
                else{
                    cnt=0;
                }
                rows[i][j]=cnt;
            }
        }
    }
    void solvecol(vector<vector<char>> &a,vector<vector<int>> &cols,int n){
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(a[j][i]=='X'){
                    cnt++;
                }
                else{
                    cnt=0;
                }
                cols[j][i]=cnt;
            }
        }
    }
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        // code here
        vector<vector<int>> rows(n,vector<int>(n,0));
        vector<vector<int>> cols(n,vector<int>(n,0));
        solverow(a,rows,n);
        solvecol(a,cols,n);
        int res=0;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int side=min(rows[i][j],cols[i][j]);
                while(side > res){
                    if(rows[i-side+1][j] >= side && cols[i][j-side+1] >= side){
                        res=side;
                    }
                    else{
                        side--;
                    }
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends