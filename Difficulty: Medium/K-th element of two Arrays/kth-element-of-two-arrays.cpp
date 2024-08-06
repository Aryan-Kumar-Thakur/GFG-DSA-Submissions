//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int n=arr1.size();
        int m=arr2.size();
        if(n>m){
            return kthElement(k,arr2,arr1);
        }
        int lo=max(0,k-m),hi=min(n,k);
        while(lo<=hi){
            int px=lo+(hi-lo)/2;
            int py=k-px;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(px-1>=0){
                l1=arr1[px-1];
            }
            if(px<n){
                r1=arr1[px];
            }
            if(py-1>=0){
                l2=arr2[py-1];
            }
            if(py<m){
                r2=arr2[py];
            }
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            else if(l1 > r2){
                hi=px-1;
            }
            else{
                lo=px+1;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends