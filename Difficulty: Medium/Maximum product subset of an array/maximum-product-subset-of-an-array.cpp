//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int mod=1e9+7;
        int n=arr.size();
        long long int prod=1;
        int zcnt=0;
        int negcnt=0;
        int mini=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                zcnt++;
                continue;
            }
            else if(arr[i]<0){
                negcnt++;
                mini=max(mini,arr[i]);
            }
            prod=(prod*arr[i])%mod;
        }
        if(zcnt==n){
            return 0;
        }
        if(negcnt%2==1){
            if(negcnt!=1 || zcnt>0 || zcnt+negcnt!=n){
                prod=(prod/mini) % mod;
            }
        }
        return (prod % mod);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends