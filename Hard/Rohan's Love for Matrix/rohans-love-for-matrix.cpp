//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    int mod=1e9+7;
    int mul(vector<vector<int>> &res,vector<vector<int>> &arr){
        int temp[2][2];
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                temp[i][j]=0;
                for(int k=0;k<2;k++){
                    temp[i][j]=(temp[i][j] % mod +  (long long)1 * res[i][k] % mod * arr[k][j] % mod) % mod;
                }
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                res[i][j]=temp[i][j] % mod;
            }
        }
    }
    vector<vector<int>> solve(vector<vector<int>> &arr,int n){
        vector<vector<int>> res(2,vector<int>(2,0));
        res[0][0]=1;
        res[1][1]=1;
        while(n){
            if(n&1){
                mul(res,arr);
            }
            mul(arr,arr);
            n>>=1;
        }
        return res;
    }
  public:
    int firstElement(int n) {
        // code here
        vector<vector<int>> arr(2,vector<int>(2,1));
        arr[1][1]=0;
        arr = solve(arr,n);
        return arr[1][0] % mod;
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends