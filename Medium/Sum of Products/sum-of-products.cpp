//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        vector<long long> temp(32,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                if(arr[i] & (1<<j)){
                    temp[j]++;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<32;i++){
            if(temp[i] > 1){
                ans+=((temp[i]*(temp[i]-1))/2)*pow(2,i);
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
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends