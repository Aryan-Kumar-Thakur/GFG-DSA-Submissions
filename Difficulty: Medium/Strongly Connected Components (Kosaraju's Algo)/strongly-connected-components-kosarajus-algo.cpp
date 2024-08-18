//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    private:
    void dfs(int i,vector<vector<int>> &adj,vector<int> &visited,stack<int> &st){
        visited[i]=1;
        for(auto it:adj[i]){
            if(!visited[it]){
            dfs(it,adj,visited,st);
            }
        }
        st.push(i);
    }
    void dfs(int i,vector<int> newadj[],vector<int> &visited){
        visited[i]=1;
        for(auto it:newadj[i]){
            if(!visited[it]){
            dfs(it,newadj,visited);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        //code here
        vector<int> visited(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        //reverse the graph
        vector<int> newadj[V];
        for(int i=0;i<V;i++){
            visited[i]=0;
            for(auto it:adj[i]){
                newadj[it].push_back(i);
            }
        }
        // again dfs
      //  vector<int> visited1(V,0);
        int cnt=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!visited[node]){
                cnt++;
                dfs(node,newadj,visited);
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends