//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
    int ans=0;
    int dfs(int s,int parent,vector<int> adj[]){
        int count=1;
        for(auto it:adj[s]){
            if(it!=parent){
                int subtree=dfs(it,s,adj);
                if(subtree % 2==0){
                    ans++;
                }
                else{
                    count++;
                }
            }
        }
        return count;
    }
public:
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> adj[n+1];
	    for(auto it:edges){
	        adj[it[0]].push_back(it[1]);
	        adj[it[1]].push_back(it[0]);
	    }
	    dfs(1,-1,adj);
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends