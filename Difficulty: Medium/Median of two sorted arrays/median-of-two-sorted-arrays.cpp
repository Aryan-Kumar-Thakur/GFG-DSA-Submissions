//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int n=arr1.size();
        int m=arr2.size();
        if(n>m){
            return SumofMiddleElements(arr2,arr1);
        }
        int lo=0,hi=n;
        int mid=(n+m+1)/2;
        while(lo<=hi){
            int px=(lo+hi)/2;
            int py=mid-px;
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
                if((n+m) & 1){
                    return max(l1,l2);
                }
                else{
                    return (max(l1,l2)+min(r1,r2));
                }
            }
            else if(l1>r2){
                hi=px-1;
            }
            else{
                lo=px+1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends