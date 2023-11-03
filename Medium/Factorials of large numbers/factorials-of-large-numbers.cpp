//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> arr;
        arr.push_back(1);
        for(int i=2;i<=N;i++){
            int carry=0;
            for(int j=0;j<arr.size();j++){
                int val=arr[j]*i+carry;
                arr[j]=val%10;
                carry=val/10;
            }
            while(carry!=0){
                arr.push_back(carry%10);
                carry=carry/10;
            }
        }
        reverse(arr.begin(),arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends