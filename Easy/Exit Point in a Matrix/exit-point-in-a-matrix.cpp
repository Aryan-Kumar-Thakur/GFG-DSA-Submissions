//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        vector<int> ans;
        int i=0,j=0;
        int l=0,r=1,u=0,d=0;
        while(i>=0 && i<n && j>=0 && j<m){
            if(matrix[i][j]==1){
                if(r){
                    r=0;
                    d=1;
                }
                else if(d){
                    d=0;
                    l=1;
                }
                else if(l){
                    u=1;
                    l=0;
                }
                else if (u){
                    r=1;
                    u=0;
                }
                matrix[i][j]=0;
            }
            if(l){
                j--;
            }
            else if(r){
                j++;
            }
            else if(u){
                i--;
            }
            else if(d){
                i++;
            }
        }
        if(i<0){
            i=0;
        }
        if(i==n){
            i=n-1;
        }
        if(j<0){
            j=0;
        }
        if(j==m){
            j=m-1;
        }
        return {i,j};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends