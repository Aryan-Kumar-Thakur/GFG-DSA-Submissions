//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        vector<int> arr(26,0);
        for(auto it:s){
            arr[it-'a']++;
        }
        int n=s.size();
        int cnt=0;
        for(int i=0;i<26;i++){
            if(arr[i]>0 && i%2==0 && arr[i] & 1){
                cnt++;
            }
            else if(arr[i]>0 && i&1 && arr[i]%2==0){
                cnt++;
            }
        }
        if(cnt & 1){
            return "ODD";
        }
        return "EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends