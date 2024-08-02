//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int> st;
        int n=mat.size();
        for(int i=0;i<n;i++){
            st.push(i);
        }
        int celeb=-1;
        while(st.size()>1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(mat[a][b]==1){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        celeb=st.top();
        st.pop();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i!=celeb && mat[i][celeb]==0){
                return -1;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=celeb && mat[celeb][i]==1){
                return -1;
            }
        }
        return celeb;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends