//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    void prevsmaller(vector<int> &left,vector<int> &arr,stack<int> &st){
        int n=arr.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                left[i]=st.top();
            }
            st.push(i);
        }
    }
    void nextsmaller(vector<int> &right,vector<int> &arr,stack<int> &st){
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=st.top();
            }
            st.push(i);
        }
    }
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        stack<int> st;
        vector<int> left(n,-1);
        vector<int> right(n,-1);
        prevsmaller(left,arr,st);
        while(!st.empty()){
            st.pop();
        }
        nextsmaller(right,arr,st);
        int ans=0;
        for(int i=0;i<n;i++){
            int a=0,b=0;
            if(left[i]!=-1){
                a=arr[left[i]];
            }
            if(right[i]!=-1){
                b=arr[right[i]];
            }
            ans=max(ans,abs(a-b));
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
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends