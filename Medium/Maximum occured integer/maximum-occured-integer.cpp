//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {

        // Your code here
          vector<pair<int,int>>dp(2*n + 1);
        int k = -1;
        for(int i=0;i<n;i++){
          dp[++k] = {l[i],1};
          dp[++k] = {r[i],-1};
        }
        sort(dp.begin(),dp.end(),[](auto &a,auto &b){
            if(a.first < b.first) return true;
            else if(a.first  == b.first){
                if(a.second >= b.second) return true;
                return false;
            }
            return false;
        });
        int mx = 0,res = 0,cnt = 0;
        for(int i = 0;i < 2*n; i++){
            cnt += dp[i].second;
            if(cnt > mx){
                mx = cnt;
                res = dp[i].first;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking testcases
    cin >> t;

    while (t--) {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++) {

            cin >> r[i];
            if (r[i] > maxx) {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends