//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int>> wt(n,vector<int>(n,1e6));
        for(auto it:edges){
            wt[it[0]][it[1]]=it[2];
            wt[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            wt[i][i]=0;
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    wt[i][j]=min(wt[i][j],wt[i][via]+wt[via][j]);
                }
            }
        }
        int ans=-1;
        int mincnt=n+1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j && wt[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            // cout<<cnt<<endl;
            if(cnt < mincnt){
                mincnt=cnt;
                ans=i;
            }
            else if(cnt==mincnt){
                ans=max(ans,i);
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends