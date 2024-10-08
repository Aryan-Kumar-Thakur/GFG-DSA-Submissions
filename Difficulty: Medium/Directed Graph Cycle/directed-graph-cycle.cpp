//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool detectCycle(int node,vector<int> adj[],vector<int> &vis,vector<int> &currentCycle){
        vis[node]=1;
        currentCycle[node]=1;
        for(auto it:adj[node]){
            if(vis[it] && currentCycle[it]==1){
                return true;
            }
            if(!vis[it] && detectCycle(it,adj,vis,currentCycle)){
                return true;
            }
        }
        currentCycle[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> currentCycle(V,0);
        for(int i=0;i<V;i++){
            if(detectCycle(i,adj,vis,currentCycle)){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends