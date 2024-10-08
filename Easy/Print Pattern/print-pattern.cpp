//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> pattern(int N){
        // code here
        vector<int> ans;
        if(N<=0){
            return {N};
        }
        int i=N-5;
        ans.push_back(N);
        bool f=1;
        if(i<=0){
                   f=0;
                }
        while(i!=N){
            ans.push_back(i);
            if(f){
                i=i-5;
                if(i<=0){
                   f=0;
                }
            }
            else{
                i=i+5;
            }
        }
        ans.push_back(N);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends