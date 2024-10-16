//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        vector<int> b=arr;
        sort(b.begin(),b.end());
        int n=arr.size();
        if(n<2){
            return 0;
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[b[i]]=i;
        }
        int cnt=0;
        for(int i=0;i<n && cnt<2;i++){
            if(arr[i]!=b[i]){
                swap(arr[i],arr[mp[arr[i]]]);
                cnt++;
            }
        }
        return (arr==b && (cnt==2 || cnt==0));
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends