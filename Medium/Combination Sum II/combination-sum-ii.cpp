//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    void solve(vector<int> &arr,int ind,int n,int k,set<vector<int>> &ans,vector<int> &output){
        if(k==0){
            ans.insert(output);
            return;
        }
        if(ind==n || k<0){
            return;
        }
        solve(arr,ind+1,n,k,ans,output);
        output.push_back(arr[ind]);
        solve(arr,ind+1,n,k-arr[ind],ans,output);
        output.pop_back();
    }
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(),arr.end());
        set<vector<int>> ans;
        vector<int> output;
        solve(arr,0,n,k,ans,output);
        vector<vector<int>> res;
        for(auto it:ans){
            res.push_back(it);
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends