//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    bool issafe(bool graph[101][101],int node,int color,vector<int> &ans,int n){
        for(int i=0;i<n;i++){
            if(graph[node][i]==1 && ans[i]==color){
                return false;
            }
        }
        return true;
    }
    bool solve(bool graph[101][101],int m,int n,vector<int> &ans){
        for(int i=0;i<n;i++){
            if(ans[i]==0){
                for(int j=1;j<=m;j++){
                    if(issafe(graph,i,j,ans,n)){
                        ans[i]=j;
                        if(solve(graph,m,n,ans)){
                            return true;
                        }
                        else{
                            ans[i]=0;
                        }
                    }
                }
                return false;
            }
        }
        return true;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> ans(n,0);
        return solve(graph,m,n,ans);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends