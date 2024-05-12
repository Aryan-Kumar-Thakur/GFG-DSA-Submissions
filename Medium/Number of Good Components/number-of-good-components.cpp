//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
    void dfs(int node,vector<int> adj[],vector<int> &res,vector<int> &vis){
        vis[node] = 1;
        res.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,res,vis);
            }
        }
    }
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vector<int> adj[v+1];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(v+1,0);
        vector<int> res;
        int ans=0;
        for(int i=1;i<=v;i++){
            if(!vis[i]){
                res.clear();
                dfs(i,adj,res,vis);
                bool f=1;
                for(int j=0;j<res.size();j++){
                    if(adj[res[j]].size() < res.size()-1){
                        f=0;
                        break;
                    }
                }
                if(f){
                    ans++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends