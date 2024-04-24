//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
        if(n<3 || m<3){
            return -1;
        }
        vector<vector<int>> pre(n,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++){
                pre[i][j]=mat[i][j-1]+pre[i][j-1];
            }
        }
        int ans=INT_MIN;
        for(int i=2;i<n;i++){
            for(int j=3;j<=m;j++){
                int x1=pre[i-2][j]-pre[i-2][j-3];
                int y1=pre[i][j]-pre[i][j-3];
                int z1=mat[i-1][j-2];
                // cout<<x1<<" "<<y1<<" "<<z1<<endl;
                ans=max(ans,x1+y1+z1);
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
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends