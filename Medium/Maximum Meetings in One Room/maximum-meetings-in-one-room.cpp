//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    // static bool comp(pair<int,int> a,pair<int,int> b){
    //     // if(a.second == b.second && a.first < b.first){
    //     //     return a > b;
    //     // }
    //     if(a.second < b.second){
    //         return b > a;
    //     }
    // }
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<int,int>> arr;
        map<pair<int,int>,int> mp;
        for(int i=0;i<N;i++){
            if(mp.find({F[i],S[i]})!=mp.end()){
                continue;
            }
            arr.push_back({F[i],S[i]});
            mp[{F[i],S[i]}]=i;
        }
        // for(auto it:arr){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        sort(arr.begin(),arr.end());
        // for(auto it:arr){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // reverse(arr.begin(),arr.end());
        vector<int> ans;
        // ans.push_back
        ans.push_back(mp[{arr[0]}]+1);
        int x=arr[0].first;
        for(int i=1;i<N;i++){
            if(arr[i].second > x){
                ans.push_back(mp[{arr[i]}]+1);
                x=arr[i].first;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends