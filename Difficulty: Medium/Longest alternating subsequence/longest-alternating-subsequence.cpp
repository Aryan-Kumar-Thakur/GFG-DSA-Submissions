//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
        stack<int> st;
        int minlen=0,maxlen=0;
        int n=arr.size();
        bool f=1;
        for(int i=0;i<n;i++){
            if(f){
                if(st.empty()){
                    st.push(arr[i]);
                }
                else if(arr[i]<=st.top()){
                    st.pop();
                    st.push(arr[i]);
                }
                else{
                    st.push(arr[i]);
                    f=0;
                }
            }
            else{
                if(arr[i]>=st.top()){
                    st.pop();
                    st.push(arr[i]);
                }
                else{
                    st.push(arr[i]);
                    f=1;
                }
            }
        }
        minlen=st.size();
        while(!st.empty()){
            st.pop();
        }
        f=1;
        for(int i=0;i<n;i++){
            if(f){
                if(st.empty()){
                    st.push(arr[i]);
                }
                else if(arr[i]>=st.top()){
                    st.pop();
                    st.push(arr[i]);
                }
                else{
                    st.push(arr[i]);
                    f=0;
                }
            }
            else{
                if(arr[i]<=st.top()){
                    st.pop();
                    st.push(arr[i]);
                }
                else{
                    st.push(arr[i]);
                    f=1;
                }
            }
        }
        maxlen=st.size();
        return max(minlen,maxlen);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends