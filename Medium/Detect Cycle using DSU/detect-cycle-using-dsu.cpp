//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    class dsu{
        public:
        vector<int> parent;
        vector<int> size;
        dsu(int n){
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
            size.resize(n,0);
        }
        int find_ulparent(int u){
            if(parent[u]==u){
                return u;
            }
            return parent[u]=find_ulparent(parent[u]);
        }
        void union_by_size(int u,int v){
            int up=find_ulparent(u);
            int vp=find_ulparent(v);
            if(up==vp) return;
            if(size[vp] > size[up]){
                swap(up,vp);
            }
            parent[vp]=up;
            size[up]+=size[vp];
        }
        
        bool checkcycle(int u,int v){
            int up=find_ulparent(u);
            int vp=find_ulparent(v);
            if(up==vp){
                return true;
            }
            return false;
        }
    };
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    dsu d1(V);
	    set<pair<int, int>> s;
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            if(s.find({i,it})!=s.end() || s.find({it,i})!=s.end()){
	                continue;
	            }
	            s.insert({i,it});
	            if(d1.checkcycle(i,it)){
	                return true;
	            }
	            d1.union_by_size(i,it);
	        }
	    }
	    return false;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends