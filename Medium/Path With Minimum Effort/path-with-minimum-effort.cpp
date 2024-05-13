//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int n, int m, vector<vector<int>> &heights) {
        // code here
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        pq.push({0,0,0});
        dis[0][0]=0;
        int ans=INT_MAX;
        while(!pq.empty()){
            int prev=pq.top()[0];
            int r=pq.top()[1];
            int c=pq.top()[2];
            pq.pop();
            if(r==n-1 && c==m-1){
                return prev;
            }
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr >=0 && nr < n && nc >=0 && nc < m){
                    int temp=max(prev,abs(heights[nr][nc]-heights[r][c]));
                    if(temp < dis[nr][nc]){
                        dis[nr][nc]=temp;
                        pq.push({temp,nr,nc});
                    }
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends