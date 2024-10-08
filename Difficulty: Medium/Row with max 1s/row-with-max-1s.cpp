//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        int i=0,j=m-1;
        int maxone=-1;
        int ans=-1;
        while(i<n && j>=0){
            if(arr[i][j]==1){
                j--;
            }
            else{
                if(m-j-1 > 0 && m-j-1 > maxone){
                    maxone=m-j-1;
                    ans=i;
                }
                i++;
            }
        }
        if(m-j-1 > 0 && m-j-1 > maxone){
            maxone=m-j-1;
            ans=i;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends