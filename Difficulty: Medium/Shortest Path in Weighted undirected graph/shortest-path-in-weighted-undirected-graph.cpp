//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define PI pair<int,int>
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> dis(n+1,1e8);
        vector<PI> adj[n+1];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        priority_queue<PI,vector<PI>,greater<PI>> pq;
        pq.push({0,1});
        dis[1]=0;
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int w=t.first;
            int node=t.second;
            for(auto it:adj[node]){
                if(w+it.second < dis[it.first]){
                    dis[it.first]=w+it.second;
                    parent[it.first]=node;
                    pq.push({w+it.second,it.first});
                }
            }
        }
        if(dis[n]==1e8) return {-1};
        vector<int> ans;
        int node=n;
        while(parent[node]!=node){
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(1);
        ans.push_back(dis[n]);
        reverse(ans.begin(),ans.end());
        // for(auto it:ans){
        //     cout<<it<<endl;
        // }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends