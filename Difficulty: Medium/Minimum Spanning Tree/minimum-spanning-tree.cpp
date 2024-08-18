//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class dsu{
    public:
    vector<int> parent;
    vector<int> size;
    dsu(int n){
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        size.resize(n+1,1);
    }
    int find_ul_parent(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=find_ul_parent(parent[u]);
    }
    void union_by_size(int u,int v){
        int up_u=find_ul_parent(u);
        int up_v=find_ul_parent(v);
        if(up_u==up_v) return;
        if(size[up_u]<size[up_v]){
            swap(up_u,up_v);
        }
        size[up_v]+=size[up_u];
        parent[up_u]=up_v;
    }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<vector<int>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                edges.push_back({it[1],i,i});
            }
        }
        sort(edges.begin(),edges.end());
        dsu d1(V);
        int sum=0;
        for(auto it:edges){
            int wt=it[0];
            int u=it[1];
            int v=it[2];
            int up_u=d1.find_ul_parent(u);
            int up_v=d1.find_ul_parent(v);
            if(up_u==up_v) continue;
            sum+=wt;
            d1.union_by_size(u,v);
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends