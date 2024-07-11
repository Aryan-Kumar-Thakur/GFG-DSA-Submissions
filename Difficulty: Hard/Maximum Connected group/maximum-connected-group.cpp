//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class disjoint{
    public:
    vector<int> size,parent;
    disjoint(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int find_ulparent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=find_ulparent(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulp_u=find_ulparent(u);
        int ulp_v=find_ulparent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
    bool isvalid(int adjrow,int adjcol,int n){
        return adjrow>=0 && adjrow<n && adjcol>=0 && adjcol<n;
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        disjoint ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                    int dr[4]={0,-1,0,1};
                    int dc[4]={-1,0,1,0};
                    for(int k=0;k<4;k++){
                        int adjrow=i+dr[k];
                        int adjcol=j+dc[k];
                        if(isvalid(adjrow,adjcol,n) && grid[adjrow][adjcol]==1){
                            int node=i*n+j;
                            int adjnode=adjrow*n+adjcol;
                            ds.unionbysize(node,adjnode);
                        }
                    }
            }
        }
        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                   if( grid[row][col]==1) continue;
                    int dr[4]={0,-1,0,1};
                    int dc[4]={-1,0,1,0};
                    unordered_set<int> st;
                    for(int i=0;i<4;i++){
                        int adjrow=row+dr[i];
                        int adjcol=col+dc[i];
                        if(isvalid(adjrow,adjcol,n)){
                            if(grid[adjrow][adjcol]==1){
                            int adjnode=adjrow*n+adjcol;
                            st.insert(ds.find_ulparent(adjnode));
                            }
                        }
                    }
                int sizeTotal=0;
                for(auto it:st){
                    sizeTotal+=ds.size[it];
                }
                ans=max(ans,sizeTotal+1);
            }
            }
        for(int c=0;c<n*n;c++){
            ans=max(ans,ds.size[ds.find_ulparent(c)]);
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends