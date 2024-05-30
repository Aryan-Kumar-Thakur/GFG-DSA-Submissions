//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        int val = n%16; // Obtained the last 4 bits
        val = val<<4; // Shifted Them by 4 bits leftwards
        int jump = n>>4; // Obtained the first 4 bits by shifting
        val+=jump; // Added Those 4 bits
        return val;

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
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends