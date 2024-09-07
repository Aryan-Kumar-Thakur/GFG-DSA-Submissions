//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        for(int i=0;i<n;i++){
            arr[i]+=i;
        }
        for(int i=1;i<n;i++){
            arr[i]=max(arr[i],arr[i-1]);
        }
        int ans=0;
        int i=0;
        while(i<n-1){
            if(i==arr[i]){
                return -1;
            }
            i=arr[i];
            ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends