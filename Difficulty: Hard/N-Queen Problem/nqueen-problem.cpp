//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    bool issafe(int r,int c,int n,vector<vector<int>> &board){
        int i=r;
        while(i>=0){
            if(board[i][c]==1){
                return false;
            }
            i--;
        }
        int j=c;
        while(j>=0){
            if(board[r][j]==1){
                return false;
            }
            j--;
        }
         i=r,j=c;
         while(i>=0 && j>=0){
             if(board[i][j]==1){
                 return false;
             }
             i--;
             j--;
         }
         i=r,j=c;
         while(i>=0 && j<n){
             if(board[i][j]==1){
                 return false;
             }
             i--;
             j++;
         }
         return true;
    }
    void solve(vector<vector<int>> &board,int r,int n,vector<vector<int>> &ans,vector<int> &out){
        if(r==n){
            ans.push_back(out);
            return;
        }
        for(int c=0;c<n;c++){
            if(issafe(r,c,n,board)){
                   board[r][c]=1;
                   out.push_back(c+1);
                   solve(board,r+1,n,ans,out);
                   board[r][c]=0;
                   out.pop_back();
                }
            }
    }
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> out;
        vector<vector<int>> board(n,vector<int>(n,0));
        solve(board,0,n,ans,out);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends