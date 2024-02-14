//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer=0;
    void dfs(int node,int parent,vector<int> adj[],vector<int> &tin,vector<int> &mint,vector<int> &vis,vector<vector<int>> &ans){
        vis[node]=1;
        tin[node]=mint[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent){
                continue;
            }
            if(!vis[it]){
                dfs(it,node,adj,tin,mint,vis,ans);
                mint[node]=min(mint[it],mint[node]);
                if(mint[it]> tin[node]){
                    if(it > node){
                        ans.push_back({node,it});
                    }
                    else{
                        ans.push_back({it,node});
                    }
                }
            }
            else{
                mint[node]=min(mint[it],mint[node]);
            }
        }
    }
public:
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    // Code here
	    vector<int> tin(v,0);
	    vector<int> mint(v,0);
	    vector<int> vis(v,0);
	    vector<vector<int>> ans;
	    dfs(0,-1,adj,tin,mint,vis,ans);
	    sort(ans.begin(),ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Endshttps://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/706303/Web/Other/bbe726f7-e9f7-4a0c-b9fa-c649299d9784_1685087730.png