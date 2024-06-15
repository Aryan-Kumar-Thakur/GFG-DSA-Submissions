//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        if (n == 1) return 10;
        vector<vector<int>> moves = {
        {0, 8},        // from 0 to 0, 8
        {1, 2, 4},     // from 1 to 1, 2, 4
        {2, 1, 3, 5},  // from 2 to 2, 1, 3, 5
        {3, 2, 6},     // from 3 to 3, 2, 6
        {4, 1, 5, 7},  // from 4 to 4, 1, 5, 7
        {5, 2, 4, 6, 8}, // from 5 to 5, 2, 4, 6, 8
        {6, 3, 5, 9},  // from 6 to 6, 3, 5, 9
        {7, 4, 8},     // from 7 to 7, 4, 8
        {8, 0, 5, 7, 9}, // from 8 to 8, 0, 5, 7, 9
        {9, 6, 8}      // from 9 to 9, 6, 8
    };
        vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
        for(int i=0;i<10;i++){
            dp[1][i]=1;
        }
        for(int i=2;i<=n;i++){
            for(int  j=0;j<10;j++){
                for(auto it:moves[j]){
                    dp[i][j]+=dp[i-1][it];
                }
            }
        }
        long long ans=0;
        for(int i=0;i<10;i++){
            ans+=dp[n][i];
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

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends