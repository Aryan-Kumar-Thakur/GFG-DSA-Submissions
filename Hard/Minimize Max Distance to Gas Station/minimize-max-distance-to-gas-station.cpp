//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    bool solve(const vector<int> &s,double mid,int k){
        int n = s.size();
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
           cnt += max(0, (int)((s[i]-s[i-1])/mid));
        }
        return cnt <= k;
    }
  public:
    double findSmallestMaxDist(vector<int> &arr, int k) {
        // Code here
        int maxi=-1;
        int n=arr.size();
        for(int i=1;i<n;i++){
            maxi=max(maxi,arr[i]-arr[i-1]);
        }
        double ans=(double)maxi;
        double lo=0,hi=(double)maxi;
        while(hi-lo > 1e-6){
            double mid=lo+(hi-lo)/2.0;
            // cout<<mid<<endl;
            if(solve(arr,mid,k)){
                ans=mid;
                hi=mid;
            }
            else{
                lo=mid;
            }
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
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends