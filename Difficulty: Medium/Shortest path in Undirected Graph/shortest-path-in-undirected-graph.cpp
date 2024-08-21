//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define PI pair<int,int>
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        priority_queue<PI,vector<PI>,greater<PI>> pq;
        vector<int> dis(N,1e8);
        dis[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int wt=pq.top().first;
            int ele=pq.top().second;
            pq.pop();
            for(auto it:adj[ele]){
                if(1+wt < dis[it]){
                    dis[it]=1+wt;
                    pq.push({dis[it],it});
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dis[i]>=1e8){
                dis[i]=-1;
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends