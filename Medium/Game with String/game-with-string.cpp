//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        vector<int> arr(26,0);
        for(auto it:s){
            arr[it-'a']++;
        }
        priority_queue<int> pq;
        for(auto it:arr){
            if(it > 0){
                pq.push(it*it);
            }
        }
        while(!pq.empty() && k>0){
            int x=pq.top();
            pq.pop();
            int y=sqrt(x)-1;
            if(y>0){
                pq.push(y*y);
            }
            k--;
        }
        int ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends