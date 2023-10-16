//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class dsu{
    public:
    vector<int> parent;
    vector<int> size;
    dsu(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        size.resize(n,1);
    }
    int findul_parent(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findul_parent(parent[u]);
    }
    void union_by_size(int u,int v){
        int up=findul_parent(u);
        int vp=findul_parent(v);
        if(up==vp) return;
        if(size[up] < size[vp]){
            parent[up]=vp;
            size[vp]+=size[up];
        }
        else{
            parent[vp]=up;
            size[up]+=size[vp];
        }
    }
};
class Solution
{
    bool isvalid(int r,int c,vector<vector<int>>& grid,int n){
        return r>=0 && r<n && c>=0 && c<n && grid[r][c]==1;
    }
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        int n=grid.size();
        dsu ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                int ind=i*n+j;
                int dr[4]={0,0,1,-1};
                int dc[4]={-1,1,0,0};
                for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(isvalid(nr,nc,grid,n)){
                    int adjind=nr*n+nc;
                    ds.union_by_size(ind,adjind);
                }
            }
        }
    }
}
int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                set<int> st;
                if(grid[i][j]==0){
                int dr[4]={0,0,1,-1};
                int dc[4]={-1,1,0,0};
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(isvalid(nr,nc,grid,n)){
                        st.insert(ds.findul_parent(nr*n+nc));
                    }
                }
                }
                int x=1;
                for(auto it:st){
                    x+=ds.size[it];
                    ans=max(ans,x);
                }
            }
        }
        for(int i=0;i<n*n;i++){
            ans=max(ans,ds.size[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends