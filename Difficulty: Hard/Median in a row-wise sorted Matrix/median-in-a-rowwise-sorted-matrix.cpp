//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    int solve(vector<int> &arr,int num,int n){
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]>num){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here   
        int n=R*C;
        int ans=n/2;
        int lo=0,hi=1e9;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int cnt=0;
            for(int i=0;i<R;i++){
                cnt+=solve(matrix[i],mid,C);
            }
            if(cnt>ans){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends