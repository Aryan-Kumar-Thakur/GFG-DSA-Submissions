//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> revadj[V];
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                revadj[it].push_back(i);
            }
        }
        vector<int> inorder(V);
        for(int i=0;i<V;i++){
            for(auto it:revadj[i]){
                inorder[it]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int ele=q.front();
            q.pop();
            ans.push_back(ele);
            for(auto it:revadj[ele]){
                inorder[it]--;
                if(inorder[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends