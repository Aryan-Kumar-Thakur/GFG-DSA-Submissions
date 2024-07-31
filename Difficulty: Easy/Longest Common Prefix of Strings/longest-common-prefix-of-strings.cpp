//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    string solve(string a,string b){
        int i=0;
        string ans="";
        while(i<a.size() && i<b.size()){
            if(a[i]==b[i]){
                ans+=a[i];
            }
            else{
                return ans;
            }
            i++;
        }
        return ans;
    }
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int n=arr.size();
        string ans=arr[0];
        for(int i=1;i<n;i++){
            ans=solve(ans,arr[i]);
        }
        if(ans.size()==0){
            return "-1";
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
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends