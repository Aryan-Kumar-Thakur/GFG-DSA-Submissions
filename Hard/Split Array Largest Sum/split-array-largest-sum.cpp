//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    bool ispossible(int mid,int arr[],int n,int k){
        int cnt=0;
        int sum=0;
        int i=0;
        while(i<n){
            if(arr[i]>mid) return 0;
            if(sum+arr[i] <= mid){
                sum+=arr[i];
            }
            else{
                cnt++;
                sum=arr[i];
            }
            i++;
        }
        cnt++;
        return (cnt <= k);
    }
  public:
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        int lo=0,hi=sum;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(ispossible(mid,arr,N,K)){
                // cout<<mid<<endl;
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends