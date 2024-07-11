//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool solve(vector<int> &stalls,int n,int k,int mid){
        int cnt=1;
        int st=stalls[0];
        for(int i=1;i<n;i++){
            if(stalls[i]-st >= mid){
                cnt++;
                st=stalls[i];
            }
        }
        return (cnt >= k);
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int lo=0,hi=1e9+2;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(solve(stalls,n,k,mid)){
                ans=max(ans,mid);
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        if(lo>=1e9+2){
            return -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends