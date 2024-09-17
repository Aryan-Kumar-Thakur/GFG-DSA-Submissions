//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if (n == 1) {
            return 0;  // If there's only one element, the difference is 0
        }

        // Sort the array
        sort(arr.begin(),arr.end());

        // Initial difference between the largest and smallest values
        int ans = arr[n - 1] - arr[0];

        // Consider the smallest and largest possible heights
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
        
        // Traverse through the array and calculate the minimum difference
        for (int i = 0; i < n - 1; i++) {
            int minHeight = min(smallest, arr[i + 1] - k);
            int maxHeight = max(largest, arr[i] + k);
            if (minHeight < 0) continue; // Skip negative heights
            ans = min(ans, maxHeight - minHeight);
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
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends