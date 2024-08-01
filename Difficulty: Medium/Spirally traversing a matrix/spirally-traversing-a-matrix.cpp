//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        vector<int> ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int sr=0,er=n-1,sc=0,ec=m-1;
        int cnt=0,total=n*m;
        while(cnt<total && sr<=er && sc<=ec){
            for(int i=sc;i<=ec && cnt<total;i++){
                ans.push_back(matrix[sr][i]);
                cnt++;
            }
            sr++;
            for(int i=sr;i<=er && cnt<total;i++){
                ans.push_back(matrix[i][ec]);
                cnt++;
            }
            ec--;
            for(int i=ec;i>=sc && cnt<total;i--){
                ans.push_back(matrix[er][i]);
                cnt++;
            }
            er--;
            for(int i=er;i>=sr && cnt<total;i--){
                ans.push_back(matrix[i][sc]);
                cnt++;
            }
            sc++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends